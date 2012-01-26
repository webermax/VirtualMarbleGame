//
//  Labyrinth.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>
#include <fstream>

#include "Labyrinth.h"

using namespace std;


Labyrinth::Labyrinth() 
{
  
   ///Random Dataset 
    for(int x=0;x<Labyrinth_size;x++)
    {
        for(int y=0;y<Labyrinth_size;y++)     
        {
            m_map[x+y*Labyrinth_size]=rand()%3;
            
        }
    }
   ///////////////// 
    
    
    cout<<"Loading Labyrinth... "<<endl;
	
    
    /////PFAD ANPASSEN
    
   // ifstream file ("/Users/Mathias/Desktop/map.raw", ios::in|ios::binary);
     ifstream file ("map.raw", ios::in|ios::binary);
    
	if (file.is_open())
	{
        
		file.read (reinterpret_cast<char *>( m_map), (sizeof(char)*Labyrinth_size*Labyrinth_size));

		
		file.close();
		
		
	}
	else cout << "Unable to open file"<<endl;
    
    
    
    
}

bool Labyrinth::getMap() {
    
    return m_map;
    
}


char Labyrinth::getBlock( int x, int y )
{
    
    return m_map[x+Labyrinth_size*y];
    
}


bool Labyrinth::hasBlock( int x, int y ) 
{
  
    if(getBlock(x,y)==0)
       
        return false;
    else
        return true;
    
}