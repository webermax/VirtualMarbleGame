//
//  Physics.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Physics_h
#define VirtualMarbleGame_Physics_h

#include "Board.h"
#include "Marble.h"

class Board;
class Marble;
class Pose;

class Physics {

public:
    
    Pose* getMarblePose();
    
private:
    
    Board* board;
    
    Marble* marble;
    
};

#endif
