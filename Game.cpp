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

using namespace std;
   Graphics *g=new Graphics();
    
    
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
    //TODO:
    //PHYSICS
}

int main(int argc, char* argv[]) 
{
    
    glutInit( &argc,  argv);
    
    
 
    
    g->init();
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc(idle);
    
    // start the action
    glutMainLoop();
    
    return 0;
}