//
//  Labyrinth.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#ifndef VirtualMarbleGame_Labyrinth_h
#define VirtualMarbleGame_Labyrinth_h

#define Labyrinth_size 30

#ifdef __linux
	#include <stdlib.h>
#endif

class Labyrinth {
    
public:
    
    Labyrinth();
    
    bool getMap();
    
    bool hasBlock( int, int );
    
private:
    
    bool m_map[Labyrinth_size][Labyrinth_size];
    
};

#endif
