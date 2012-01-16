//
//  Graphics.cpp
//  VirtualMarbleGame
//
//  Created by Kanzler Mathias on 15.01.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//




#include <iostream>
#include <fstream>
//#include <iomanip>
#include <opengl/opengl.h>
#include <GLUT/glut.h>
using namespace std;

GLuint block;



unsigned char map[30][30];
double ry;

void resize( int width, int height) 
{

    glViewport( 0, 0, width, height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45, ((double)width/(double)height), 0.01, 100 );

    glutPostRedisplay();
}



void buildBlock()
{
     block = glGenLists(1);
    
   
    glNewList(block, GL_COMPILE);
    
glBegin(GL_QUADS);
    // Bottom 
    glNormal3f(0,-1,0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f, -0.0f, -0.0f);  
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -0.0f, -0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f);  
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f);  
    
    // Top Face
    glNormal3f(0,1,0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f); 
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f,  1.0f,  1.0f);  
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);  
    
    // Front
    glNormal3f(0,0,1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f); 
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f); 
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); 
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f,  1.0f); 
    
    // Back 
    glNormal3f(0,0,-1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f, -0.0f);  
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f);  
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);  
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -0.0f, -0.0f);  
    
    // Right 
    glNormal3f(1,0,0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -0.0f, -0.0f);  
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -0.0f);  
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -0.0f,  1.0f);  
    
    // Left 
    glNormal3f(-1,0,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, -0.0f, -0.0f);  
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, -0.0f,  1.0f);  
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f,  1.0f,  1.0f); 
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f,  1.0f, -0.0f); 
  
    glEnd();
    
    glEndList();  
    
    
}



GLuint LoadTGATexture( const char * filename)
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


void buildBoard()
{
    
    
    for(int x=0;x<30;x++)
        for(int y=0;y<30;y++)     
        {
            map[x][y]=rand()%3;
            
        }

}

void renderBoard()
{
    
    for(int x=0;x<30;x++)
    for(int y=0;y<30;y++)     
    {
       if(map[x][y]==1)
       {
           glTranslatef(x,y,0);
           
           glCallList(block);
           
           glTranslatef(-x,-y,0);

       }
        
        
    }
    
    
}






void display() 
{
    // clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
   
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    

    glColor4f(1,1,1,1);
     
	glTranslatef(0,-5,-40);
    glRotatef(90,1,0,0);
    
    glRotatef(ry,0,0,1);
    glTranslatef(-15,-15,0);
    
    ry+=0.01;

   
   

    renderBoard();
       
       // glutSolidSphere( 1, 10, 10 );
    
    glFlush();
    glutSwapBuffers();
    	glutPostRedisplay();
}

void idle()
{
    }


void init()
{
    
    // initialize the window system
   
    glutInitWindowSize( 600,600);
    
    
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("Graphics");
    
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
    
    
    
    buildBlock();
    buildBoard();
    
}


int main(int argc, char* argv[]) 
{
    
     glutInit( &argc,  argv);
    init();
  
    
    // make functions known to GLUT
    glutDisplayFunc( display );
    glutReshapeFunc( resize  );
    glutIdleFunc(idle);
    
 
    // start the action
    glutMainLoop();
    
    return 0;
}