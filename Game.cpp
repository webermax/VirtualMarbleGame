//
//  Game.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

// TODO: release resources
// TODO: move display(), idle(), void resize(int w, int h) to graphics.cpp

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
    //TODO:
    //PHYSICS
    i += 0.005;
    i = fmod(i, M_PI);
    m->setY(abs(sin(i)));
}

int main(int argc, char* argv[]) 
{
    v = new VideoManager();
    
    m = new Marble(0.0, 0.0, -20.0, 1.0, 1.0);
    
    l = new Labyrinth();
    
    g = new Graphics(m, l, v);
    
    glutInit( &argc,  argv);
    
    g->init();
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc( idle );
    
    // start the action
    glutMainLoop();
    
    return 0;
}
