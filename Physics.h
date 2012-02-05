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
    
    Physics(Labyrinth*, Marble*, Pose*, Pose*);
    
    ~Physics();
    
    void process();
    void switch90();
    
    bool  rotate90;
    
private:
    void CheckFinish();
    
    void collisionDetection();
    
    Labyrinth* m_labyrinth;
    
    Marble* m_marble;
    
    Pose* m_pose;
    
    Pose* m_gravity;
    
    
    float x_new;
    
    float y_new;
    
    float z_new;
    
    void collideX(float);
    
    void collideY(float);
    
};

#endif
