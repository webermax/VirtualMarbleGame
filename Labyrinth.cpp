//
//  Labyrinth.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>

#include "Labyrinth.h"

Labyrinth::Labyrinth() {
    
    for(int x=0;x<30;x++)
    {
        for(int y=0;y<30;y++)     
        {
            m_map[x][y]=rand()%3;
            
        }
    }
    
}

bool Labyrinth::getMap() {
    
    return m_map;
    
}

bool Labyrinth::hasBlock( int x, int y ) {
    
    return m_map[x][y];
    
}