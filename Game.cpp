//
//  Game.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>

#include <GLUT/glut.h>

#include "Graphics.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    
    glutInit( &argc,  argv);
    
    Graphics::init();
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc(idle);
    
    // start the action
    glutMainLoop();
    
    return 0;
}