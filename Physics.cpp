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
    
    // FIXME:
    m_marble->setZ(+m_marble->getRadius());
}

void Physics::Collision()
{
if(abs(m_marble->m_x)>Labyrinth_size /2)
    m_marble->v_x*=-1;
 
    if(abs(m_marble->m_y)>Labyrinth_size /2)
        m_marble->v_y*=-1;
}







void Physics::process()
{
 
    float t = 0.033;
    
    // alert: horizontal mode!!!
    
    // calculate components of gravity vector
    // assuming g = ( x = 0, y = -9.81, z = 0 ) in camera coordinates

//    float a_x = -m_pose->matrix[8] * 9.81;
//    float a_y = -m_pose->matrix[9] * 9.81;
//    float a_z = -m_pose->matrix[10] * 9.81;
    
    float a_x = -m_pose->matrix[4] * 9.81;
    float a_y = -m_pose->matrix[5] * 9.81;
    float a_z = -m_pose->matrix[6] * 9.81;
    
    m_marble->v_x *=0.98;
    m_marble->v_y *=0.98;
    
    // calculate speed
    m_marble->v_x += a_x * t*10;
    m_marble->v_y += a_y * t*10;
    
    // calculate position
    m_marble->m_x += m_marble->v_x * t;
    m_marble->m_y += m_marble->v_y * t;
    
    
    Collision();    
}

Physics::~Physics()
{
    
}

