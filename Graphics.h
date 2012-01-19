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
#include <opengl/OpenGL.h>

class Board;
class Marble;
class VideoManager;

class Graphics {
    
public:
    
    Graphics(Marble* marble);  
    
    void display();
 
    void init();
    
    void resize( int width, int height);
    
    void setMarble(Marble* marble);
    
    Marble* getMarble();
    
private:
    
    Board* m_board;
    
    Marble* m_marble;
    
    VideoManager* m_videoManager;
   
    void buildBlock();
    
    GLuint LoadTGATexture( const char * filename);
    
    void buildBoard();
    
    void renderBoard();
    
    void renderMarble();
    
};

#endif
