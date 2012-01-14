//
//  Graphics.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Graphics_h
#define VirtualMarbleGame_Graphics_h

#include "Board.h"
#include "Marble.h"
#include "VideoManager.h"

class Board;
class Marble;
class VideoManager;

class Graphics {
    
public:
    
    void render();
    
private:
    
    Board* board;
    
    Marble* marble;
    
    VideoManager* videoManager;
    
};

#endif
