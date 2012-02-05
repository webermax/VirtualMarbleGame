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
    
    Graphics(bool, Marble*, Labyrinth*, VideoManager*, Pose*, Pose*);  
    
    void display();
 
    int init();
    
    void resize( int, int);
    
    void idle();
    
    void setMarble(Marble*);
    
    Marble* getMarble();
    
    void switchCalibrate();
    
private:
    
    Board* m_board;
    
    Marble* m_marble;
    
    Labyrinth* m_labyrinth;
    
    VideoManager* m_videoManager;
   
    Pose* m_pose;
    
    Pose* m_gravity;
    
    void drawVector();
    
    void buildBlock( bool, bool, bool, bool, bool, bool );
    
    GLuint LoadTGATexture( const char * filename);
    
    void renderBoard();
    
    void renderMarble();
    
    void renderGravityVector();
    
    GLuint block;
    
    GLuint m_texture_labyrinth;
    
    GLuint m_texture_marble;
    
    double ry;
    
    bool m_debug;
    
    bool m_calibrate;
    
};

#endif
