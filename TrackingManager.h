//
//  TrackingManager.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Tracking_h
#define VirtualMarbleGame_Tracking_h

#include "VideoManager.h"

class VideoManager;
class BoardMatrix;

class TrackingManager {
    
public:
    
    BoardMatrix* getBoardMatrix();
    
private:
    
    VideoManager* videoManager;
    
};

#endif
