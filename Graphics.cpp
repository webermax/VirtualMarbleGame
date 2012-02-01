//
//  Graphics.cpp
//  VirtualMarbleGame
//
//  Created by Kanzler Mathias on 15.01.12.
//

#include "Graphics.h"

#include <iostream>
#include <fstream>
//#include <iomanip>

using namespace std;

void Graphics::resize( int width, int height) 
{

    glViewport( 0, 0, width, height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective( CAM_ANGLE, ((double)width/(double)height), 0.01, 100 );

    glutPostRedisplay();
}

void Graphics::idle() 
{
    //m_videoManager->capture();
}

void Graphics::buildBlock( bool bottom = 1, bool top = 1, bool front = 1, bool back = 1, bool right = 1, bool left = 1 )
{
    block = glGenLists(1);
   
    glNewList(block, GL_COMPILE);
    
    glBegin(GL_QUADS);
    
    // Bottom
    if(bottom) {
        glNormal3f(0,-1,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f, -0.0f, -0.0f);  
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -0.0f, -0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f);
    }
    
    // Top
    if(top) {
        glNormal3f(0,1,0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);
    }
    
    // Front
    if(front) {
        glNormal3f(0,0,1);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f,  1.0f);
    }
    
    // Back
    if(back) {
        glNormal3f(0,0,-1);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f, -0.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -0.0f, -0.0f);
    }
    
    // Right
    if(right) {
        glNormal3f(1,0,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -0.0f, -0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f);
    }
    
    // Left
    if(left) {
        glNormal3f(-1,0,0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, -0.0f, -0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f);
    }
  
    glEnd();
    
    glEndList();  
    
    
}



GLuint Graphics::LoadTGATexture( const char * filename)
{
	struct HeaderStruct {
        char type;  // Typ 2 (24/32-Bit TGA ohne Kompression),
        short  w, h;  // Width, Height
        char bpp;  // Bits per Pixel
        char *data; // Pixels, dynamic length
	} header;
	
	GLuint texture=0;
	
	ifstream file (filename, ios::in|ios::binary);
	
	if (file.is_open())
	{
        
	
		
		// type
		file.seekg (2);
		
		file>>header.type;
        
		file.seekg( 12);
		file.read (reinterpret_cast<char *>(&header.w), 5);

		
	     
        // data
        int bytes = header.w * header.h * header.bpp/8;
        header.data=new char [bytes];
		
        
        file.seekg(18);
        file.read(header.data,bytes);
        
        file.close();
        
        if(header.type==2)
        {
            glGenTextures( 1, &texture ); //generate the texture with 	the loaded data
            glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture	to it’s array
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,   GL_MODULATE ); //set texture environment parameters
            
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            
            if (header.bpp/8==3)
                glTexImage2D(GL_TEXTURE_2D, 0, header.bpp/8, header.w, header.h, 0, GL_BGR, GL_UNSIGNED_BYTE, header.data);
            else 
                glTexImage2D(GL_TEXTURE_2D, 0, header.bpp/8, header.w, header.h, 0, GL_BGRA, GL_UNSIGNED_BYTE, header.data);
		
        }
		
		delete[]  header.data;
	}
	
    return texture;		
}

Graphics::Graphics(Marble* marble, Labyrinth* labyrinth, VideoManager* videoManager, Pose* pose)
{
    m_marble = marble;
    m_labyrinth = labyrinth;
    m_videoManager = videoManager;
    m_pose =pose;
}


void Graphics::renderBoard()
{
    glDisable(GL_TEXTURE_GEN_S); 
    glDisable(GL_TEXTURE_GEN_T); 
	
	
    
    glBindTexture(GL_TEXTURE_2D, m_texture_labyrinth);
    
    glPushMatrix();
    glScalef(0.02, 0.02, 0.02);
    glTranslatef(-Labyrinth_size/2,-Labyrinth_size/2,0);
    
    for(int x=0;x<Labyrinth_size;x++)
    {
        for(int y=0;y<Labyrinth_size;y++)  
        {
            if(m_labyrinth->hasBlock(x,y)==true)
            {
                glTranslatef(x,y,0);
                glCallList(block);
                glTranslatef(-x,-y,0);
            }
        }
    }

    glTranslatef(Labyrinth_size/2,Labyrinth_size/2,0);
    glPopMatrix();
}

void Graphics::renderMarble()
{
//    glEnable(GL_TEXTURE_GEN_S); 
//    glEnable(GL_TEXTURE_GEN_T);
//    glBindTexture(GL_TEXTURE_2D, m_texture_marble);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3f( 1.0f,0.0f,0.0f);
    
    glPushMatrix();
    
    glScalef(0.02, 0.02, 0.02);
    glTranslatef( m_marble->getX(), m_marble->getY(), m_marble->getZ() );
    
    glutSolidSphere( m_marble->getRadius(), 30, 30 );
    
    // calculate components of gravity vector
    // assuming g = ( x = 0, y = -9.81, z = 0 ) in camera coordinates
    float x = -m_pose->matrix[4] * 9.81;
    float y = -m_pose->matrix[5] * 9.81;
    float z = -m_pose->matrix[6] * 9.81;
    
    //printf("(x: %f, y: %f, z: %f)\n", x ,y ,z);
    
    // draw gravity vector components
    glBegin(GL_LINES);
    glLineWidth(100);
    
    glColor3f(1,0,0); // red
    glVertex3f(0,0,0);
    glVertex3f(x,0,0);
    
    glColor3f(0,1,0); // green
    glVertex3f(0,0,0);
    glVertex3f(0,y,0);
    
    glColor3f(0,0,1); // blue
    glVertex3f(0,0,0);
    glVertex3f(0,0,z);
    
    glColor3f(1,1,0); // yellow
    glVertex3f(0,0,0);
    glVertex3f(x,y,z);
    
    glEnd();
    
    glPopMatrix();
    
}

void Graphics::drawVector()
{
    
    
    glLoadIdentity();
    
    float x=  m_pose->matrix[0+0]+  m_pose->matrix[0+1]+  m_pose->matrix[0+2];
    float y=  m_pose->matrix[4+0]+  m_pose->matrix[4+1]+  m_pose->matrix[4+2];
    float z=  m_pose->matrix[4+4+0]+  m_pose->matrix[4+4+1]+  m_pose->matrix[4+4+2];

    
    
    glTranslated(0,0,-7);
  //  glRotatef(45,1,1,0);
    
    
    
    glBegin(GL_TRIANGLES);
    glColor3f(x,y,z);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    

    
    
    glVertex3f(x,y,z);
    glEnd();
    
       
}



void Graphics::display() 
{
    // clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
   
    // draw background image
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable( GL_DEPTH_TEST );
    
    glMatrixMode( GL_PROJECTION );
     glPushMatrix();

    glLoadIdentity();
    gluOrtho2D( 0.0, CAM_WIDTH, 0.0, CAM_HEIGHT );
    
    glRasterPos2i( 0, CAM_HEIGHT-1 );
    m_videoManager->capture();
    glDrawPixels( CAM_WIDTH, CAM_HEIGHT, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_videoManager->getImage() );
    
     glPopMatrix();
    
    glEnable(GL_DEPTH_TEST);
    
    // move to origin
    glMatrixMode( GL_MODELVIEW );
  
    glColor4f(1,1,1,1);
    
    glLoadTransposeMatrixf( m_pose->matrix );
    
    // render game board with labyrinth and maze
    renderBoard();

    // render marble
    renderMarble();
    
    glFlush();
    glutSwapBuffers();
    // glutPostRedisplay();

}


int Graphics::init()
{
    
    // initialize the window system
   
    glutInitWindowSize( 640,480);
    
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    int windowId = glutCreateWindow("Virtual Marble Game");
    
    // initialize the GL library
    
    // pixel storage/packing stuff
    glPixelStorei( GL_PACK_ALIGNMENT,   1 );
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glPixelZoom( 1.0, -1.0 );
    
    // enable and set colors
    glEnable( GL_COLOR_MATERIAL );
    glClearColor( 0, 0, 0, 1.0 );
    
    // enable and set depth parameters
    glEnable( GL_DEPTH_TEST );
    glClearDepth( 1.0 );
    
    // light parameters
    GLfloat light_pos[] = { 10.0, 10.0, 10.0, 0.0 };
    GLfloat light_amb[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_dif[] = { 0.7, 0.7, 0.7, 1.0 };
    
    // enable lighting
    glLightfv( GL_LIGHT0, GL_POSITION, light_pos );
    glLightfv( GL_LIGHT0, GL_AMBIENT,  light_amb );
    glLightfv( GL_LIGHT0, GL_DIFFUSE,  light_dif );
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );  
    
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);   
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);  
    
    buildBlock();
    
    m_texture_labyrinth = LoadTGATexture( "labyrinth.tga");
    m_texture_marble = LoadTGATexture( "marble.tga");
    
    glEnable(GL_TEXTURE_2D);
    
    return windowId;
    
}
