//
//  Game.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>

#include <GLUT/glut.h>
#include <opengl/OpenGL.h>
#include "Graphics.h"
#include "Marble.h"

using namespace std;

Marble *m;

Graphics *g;
    
    
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
    
    m = new Marble(0.0, 0.0, -20.0, 1.0, 1.0);
    
    g = new Graphics(m);
    
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