//
//  Physics.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>

#include "Physics.h"

Physics::Physics(Labyrinth* labyrinth, Marble* marble, Pose* pose)
{
    m_labyrinth = labyrinth;
    m_marble = marble;
    m_pose = pose;
}

void Physics::process()
{
    double newX=m_marble->m_x;
    double newY=m_marble->m_y;
    
    //RotationsMatrix:
    float x=  m_pose->matrix[0+0]+  m_pose->matrix[0+1]+  m_pose->matrix[0+2];
    float y=  m_pose->matrix[4+0]+  m_pose->matrix[4+1]+  m_pose->matrix[4+2];
    float z=  m_pose->matrix[4+4+0]+  m_pose->matrix[4+4+1]+  m_pose->matrix[4+4+2];
    
    
    
    //Speed
    newX+=m_marble->v_x;
    newY+=m_marble->v_y;
    
    
    //Recalculate Velocity
    
    m_marble->v_x+=x*0.0001;
    m_marble->v_y+=y*0.0001;
    
    
    
    
    
    m_marble->setX(newX);
    m_marble->setY(newY);
    
    
    
    m_marble->setZ(-m_marble->getRadius());
}

Physics::~Physics()
{
    
}

