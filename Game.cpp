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

double i = 0.0;

void idle()
{
    g->idle();
}

static void timer(int value)
{
    /* Do timer processing */
    /* maybe glutPostRedisplay(), if necessary */
    
    //TODO:
    //PHYSICS
    i += 0.05;
    i = fmod(i, M_PI);
    m->setY(abs(sin(i)));
    
    //glutPostRedisplay();
    
    /* call back again after elapsedUSecs have passed */
    glutTimerFunc (10, timer, value);
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
    //glutTimerFunc(10, timer, 1);
    
    // start the action
    glutMainLoop();
    
    return 0;
}
