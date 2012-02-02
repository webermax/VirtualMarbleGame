//
//  Physics.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#ifndef VirtualMarbleGame_Physics_h
#define VirtualMarbleGame_Physics_h

#include "Labyrinth.h"
#include "Marble.h"
#include "Pose.h"

class Labyrinth;
class Marble;
class Pose;

class Physics {

public:
    
    Physics(Labyrinth*, Marble*, Pose*);
    
    ~Physics();
    
    void process();
    
private:
    
    void CollisionDetection();
    
    Labyrinth* m_labyrinth;
    
    Marble* m_marble;
    
    Pose* m_pose;
    
    float x_new;
    
    float y_new;
    
    float z_new;
    
};

#endif
