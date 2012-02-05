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
#include "Physics.h"

using namespace std;

Marble* marble;
Graphics* graphics;
Labyrinth* labyrinth;
VideoManager* videoManager;
TrackingManager* trackingManager;
Pose* pose;
Pose* gravity;
Physics* physics;

void display();
void resize( int, int );
void idle();
static void trackingTimer(int value);
static void ballTimer(int value);
static void physicsTimer(int value);
void hitkey( unsigned char key, int x, int y );
void checkFinish( int value);

int windowId;
int t = 30;
bool debug = false;
int cameraNumber = true;

void hitkey( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 27: // Escape key
            glutDestroyWindow ( windowId );
            exit (0);
            break;
        case 108: // l key
            labyrinth->createMaze();
            break;
        case 'n': // n key
            marble->reset();
            break;
    }
    //glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) 
{
  

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




void checkFinish( int value)
{
    if(marble->m_x>Labyrinth_size-1 && marble->m_y>Labyrinth_size-1)
    {
        
        //TODO: Play some Sounds..
        
       
         labyrinth->createMaze(); 
   marble->reset();
   
   
        
        
    }
     glutTimerFunc (t, checkFinish, value);
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

static void trackingTimer(int value)
{
    trackingManager->process();
    
    glutPostRedisplay();
    
    glutTimerFunc (t, trackingTimer, value);
}

static void physicsTimer(int value)
{
    physics -> process();
    
    glutTimerFunc (t, physicsTimer, value);
}

int main(int argc, char* argv[])
{
    cout << "Starting: " << argv[0] << "\n";
    
    if(argc > 1 && *argv[1] == '1') 
    {
        debug =true;
        cout << "Debug mode.\n";
    }
    
   if(argc > 2) 
    {
        cameraNumber = atoi(argv[2]);
        cout << "Using camera: " << argv[2] << ".\n";
    }
    
    glutInit( &argc,  argv);
    
    videoManager = new VideoManager(cameraNumber);
    pose = new Pose();
    gravity = new Pose();
    trackingManager = new TrackingManager(debug, videoManager, pose, gravity);
    marble = new Marble(0, 0, -3, 0.4, 1);
    labyrinth = new Labyrinth();
    graphics = new Graphics(debug, marble, labyrinth, videoManager, pose);
    physics = new Physics(labyrinth, marble, pose);
    
    windowId = graphics->init();
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc( idle );
    glutKeyboardFunc( hitkey );
    glutTimerFunc(t, trackingTimer, 1);
    glutTimerFunc(t, physicsTimer, 1);
    glutTimerFunc(t, checkFinish, 1);
    //glutMouseFunc(mouse);
    
    // start the action
    glutMainLoop();
    
    return 0;
}
