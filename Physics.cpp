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
    
    
    
}

Physics::~Physics()
{
    
}

