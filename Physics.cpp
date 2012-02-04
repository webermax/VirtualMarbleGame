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

void Physics::collideX(float border) {
    m_marble->v_x *= -0.5;
    m_marble->m_x = border;
}

void Physics::collideY(float border) {
    m_marble->v_y *= -0.5;
    m_marble->m_y = border;
}

int x_old = -1, y_old = -1;

/**
 We check all 8 neighbours here
**/
void Physics::collisionDetection()
{
//    /* Position in maze grid has changed */
//    if((int)(m_marble->m_x) != x_old || (int)(m_marble->m_y) != y_old ) {
//        
//        x_old = (int)(m_marble->m_x);
//        y_old = (int)(m_marble->m_y);
//        
//        printf("we are in %i, %i\n", (int)(m_marble->m_x), (int)(m_marble->m_y));
//        
//        printf("checking %i, %i: %i\n", (int)(m_marble->m_x) + 1, (int)(m_marble->m_y), m_labyrinth->hasBlock(m_marble->m_x+1, m_marble->m_y));
//        printf("checking %i, %i: %i\n", (int)(m_marble->m_x) - 1, (int)(m_marble->m_y), m_labyrinth->hasBlock(m_marble->m_x-1, m_marble->m_y));
//        printf("checking %i, %i: %i\n", (int)(m_marble->m_x), (int)(m_marble->m_y) + 1, m_labyrinth->hasBlock(m_marble->m_x, m_marble->m_y + 1));
//        printf("checking %i, %i: %i\n", (int)(m_marble->m_x), (int)(m_marble->m_y) - 1, m_labyrinth->hasBlock(m_marble->m_x, m_marble->m_y - 1));
//        
//    }
    
    /* Level borders */
    float max = Labyrinth_size - m_marble->m_radius;
    float min = m_marble->m_radius;
    if(x_new > max) {
        collideX(max);
    } else if(x_new < min) {
        collideX(min);
    }
    if(y_new > max) {
        collideY(max);
    } else if(y_new < min) {
        collideY(min);
    }
    
    /* Maze blocks: x + 1 */
    if(m_labyrinth->hasBlock(m_marble->m_x + 1, m_marble->m_y)) {
        if((int)(x_new + m_marble->m_radius) > (int)m_marble->m_x) {
            collideX((int)(m_marble->m_x + 1) - m_marble->m_radius);
        }
    }
    
    /* Maze blocks: x - 1 */
    if(m_labyrinth->hasBlock(m_marble->m_x - 1, m_marble->m_y)) {
        if((int)(x_new - m_marble->m_radius) < (int)m_marble->m_x) {
            collideX((int)(m_marble->m_x) + m_marble->m_radius);
        }
    }
    
    /* Maze blocks: y + 1 */
    if(m_labyrinth->hasBlock(m_marble->m_x, m_marble->m_y + 1)) {
        if((int)(y_new + m_marble->m_radius) > (int)m_marble->m_y) {
            collideY((int)(m_marble->m_y + 1) - m_marble->m_radius);
        }
    }
    
    /* Maze blocks: y - 1 */
    if(m_labyrinth->hasBlock(m_marble->m_x, m_marble->m_y - 1)) {
        if((int)(y_new - m_marble->m_radius) < (int)m_marble->m_y) {
            collideY((int)(m_marble->m_y) + m_marble->m_radius);
        }
    }

}




void Physics::process()
{
    float t = 0.033;
    
    // calculate components of gravity vector
    // assuming g = ( x = 0, y = -9.81, z = 0 ) in camera coordinates

//    float a_x = -m_pose->matrix[8] * 9.81;
//    float a_y = -m_pose->matrix[9] * 9.81;
//    float a_z = -m_pose->matrix[10] * 9.81;
    
    float a_x = -m_pose->matrix[4] * 9.81;
    float a_y = -m_pose->matrix[5] * 9.81;
//    float a_z = -m_pose->matrix[6] * 9.81;
    
    // calculate speed
    m_marble->v_x += a_x * t * 10;
    m_marble->v_y += a_y * t * 10;
    
    // calculate new position
    x_new = m_marble->m_x + m_marble->v_x * t;
    y_new = m_marble->m_y + m_marble->v_y * t;
    
    // collision with level boundaries?
    collisionDetection(); 
    
    // set new position
    float increment_x = m_marble->v_x * t;
    //if(abs(increment_x) > 0.05)
        m_marble->m_x += increment_x;
    float increment_y = m_marble->v_y * t;
    //if(abs(increment_y) > 0.05)
        m_marble->m_y += increment_y;
    
  
}

Physics::~Physics()
{
    
}
