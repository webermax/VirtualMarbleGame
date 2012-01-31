//
//  Labyrinth.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>
#include <fstream>

#include "Labyrinth.h"
#include "Labyrinth.h"

#include "maze.c"

using namespace std;

void Labyrinth::createMaze()
{
    GenerateMaze(m_map, Labyrinth_size, Labyrinth_size);
}

Labyrinth::Labyrinth() 
{
    cout<<"Loading Labyrinth... "<<endl;
    
    /////PFAD ANPASSEN
    
    // ifstream file ("/Users/Mathias/Desktop/map.raw", ios::in|ios::binary);
    ifstream file ("map.raw", ios::in|ios::binary);
    
	if (file.is_open())
	{
		file.read (reinterpret_cast<char *>( m_map), (sizeof(char)*Labyrinth_size*Labyrinth_size));
		file.close();
		
	}
	else {
        cout << "Unable to open file"<<endl;
        createMaze();
        
        m_map[0]=0;
    }
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