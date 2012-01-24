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

using namespace std;

Marble *m;
Graphics *g;
Labyrinth *l;
VideoManager *v;

void display();
void resize( int, int );
void idle();
static void timer(int value);
void hitkey( unsigned char key, int x, int y );

int windowId;
int t = 30;

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
    g->display();
}

void resize(int w, int h)
{
    g->resize(w,h);
}

void idle()
{
    g->idle();
}

double yStart = 5.0;
double speed = 0.0;
double y = yStart;
double d = t / 1000.0;
float a = -9.81;
static void timer(int value)
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
    
    m->setY(y);
    
    glutPostRedisplay();
    
    /* call back again after elapsedUSecs have passed */
    glutTimerFunc (t, timer, value);
}

int main(int argc, char* argv[])
{
    cout << "Startup\n";
    
    v = new VideoManager();
    m = new Marble(0, 0, -20, 1, 1);
    l = new Labyrinth();
    g = new Graphics(m, l, v);
    
    glutInit( &argc,  argv);
    
    windowId = g->init();
    
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
