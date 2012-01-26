//
//  Game.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

// TODO: release resources

#include <iostream>

#include "Graphics.h"
#include "Marble.h"
#include "Labyrinth.h"
#include "VideoManager.h"
#include "Pose.h"

using namespace std;

Marble* marble;
Graphics* graphics;
Labyrinth* labyrinth;
VideoManager* videoManager;
TrackingManager* trackingManager;
Pose* pose;

void display();
void resize( int, int );
void idle();
static void timer(int value);
void hitkey( unsigned char key, int x, int y );

int windowId;
int t = 30;
bool debug = false;

void hitkey( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 27: // Escape key
            glutDestroyWindow ( windowId );
            exit (0);
            break;
    }
    //glutPostRedisplay();
}
    
void display()
{    
    graphics->display();
}

void resize(int w, int h)
{
    graphics->resize(w,h);
}

void idle()
{
    graphics->idle();
}

double yStart = 5.0;
double speed = 0.0;
double y = yStart;
double d = t / 1000.0;
float a = -9.81;
static void ballTimer(int value)
{
    /* Do timer processing */
    /* maybe glutPostRedisplay(), if necessary */
    
    //TODO:
    //PHYSICS
//    x += 0.1;
//    x = fmod(x, M_PI);
//    m->setY(3 * abs(sin(x)));
    
    speed += a * d;

    y += speed * d;
    
    if ( y < 0 && speed <0 ) speed *= -1;
    
    marble->setY(y);
    
    glutPostRedisplay();
    
    /* call back again after elapsedUSecs have passed */
    glutTimerFunc (t, ballTimer, value);
}

static void timer(int value)
{
    trackingManager->process();
    
    glutPostRedisplay();
    
    glutTimerFunc (t, timer, value);
}

int main(int argc, char* argv[])
{
    cout << "Starting up with the following arguments:\n";
    
    for (int i=0; i<argc; i++) {
        printf("%s\n", argv[i]);
        if(*argv[i] == true) debug = true;
    }
    
    videoManager = new VideoManager();
    pose = new Pose();
    trackingManager = new TrackingManager(debug, videoManager, pose);
    marble = new Marble(0, 0, -20, 1, 1);
    labyrinth = new Labyrinth();
    graphics = new Graphics(marble, labyrinth, videoManager, pose);
    
    //glutInit( &argc,  argv);
    
    windowId = graphics->init();
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc( idle );
    glutKeyboardFunc( hitkey );
    glutTimerFunc(t, timer, 1);
    
    // start the action
    glutMainLoop();
    
    return 0;
}
