//
//  Graphics.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Graphics_h
#define VirtualMarbleGame_Graphics_h

#ifdef __linux
	#include <GL/gl.h>
	#include <GL/freeglut.h>
#else
	#include <opengl/OpenGL.h>
	#include <GLUT/glut.h>
#endif

#include "Board.h"
#include "Marble.h"
#include "VideoManager.h"
#include "Labyrinth.h"

class Board;
class Marble;
class Labyrinth;
class VideoManager;
class Pose;

class Graphics {
    
public:
    
    Graphics(Marble*, Labyrinth*, VideoManager*, Pose*);  
    
    void display();
 
    int init();
    
    void resize( int, int);
    
    void idle();
    
    void setMarble(Marble*);
    
    Marble* getMarble();
    
private:
    
    Board* m_board;
    
    Marble* m_marble;
    
    Labyrinth* m_labyrinth;
    
    VideoManager* m_videoManager;
   
    Pose* m_pose;
    
    void buildBlock( bool, bool, bool, bool, bool, bool );
    
    GLuint LoadTGATexture( const char * filename);
    
    void renderBoard();
    
    void renderMarble();
    
};

#endif
