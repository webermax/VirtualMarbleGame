//
//  Marble.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Marble_h
#define VirtualMarbleGame_Marble_h

#include "Physics.h"
#include "Pose.h"

class Physics;
class Pose;

class Marble {
    
public:
    
    Pose* getPose();
    
    float getRadius();
    
    float getWeight();
    
private:
    
    Pose* pose;
    
    Physics* physics;
    
    float radius;
    
    float weight;
    
};

#endif
