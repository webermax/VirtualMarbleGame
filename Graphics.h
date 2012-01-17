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
    
    void display();
    
    void idle();
    
    void init();
    
private:
    
    Board* board;
    
    Marble* marble;
    
    VideoManager* videoManager;
    
    void resize( int width, int height);
    
    void buildBlock();
    
    GLuint LoadTGATexture( const char * filename);
    
    void buildBoard();
    
    void renderBoard();
    
};

#endif
