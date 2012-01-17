//
//  Board.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Board_h
#define VirtualMarbleGame_Board_h

#include "TrackingManager.h"

class TrackingManager;
class Pose;
class Labyrinth;

class Board {
    
public:
    
    Pose* getPose();
    Labyrinth* getLabyrinth();
    
private:
    
    TrackingManager* trackingManager;
    
    Pose* pose;
    
    Labyrinth* labyrinth;
    
};

#endif
