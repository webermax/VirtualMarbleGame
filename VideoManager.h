//
//  VideoManager.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#ifndef VirtualMarbleGame_VideoManager_h
#define VirtualMarbleGame_VideoManager_h

#define CAM_WIDTH 640
#define CAM_HEIGHT 480

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

class VideoManager {
    
public:
    
    VideoManager();
    
    ~VideoManager();
    
    void initVideoStream();
    
    unsigned char *getImage();
    
    void capture();
    
    IplImage* getIplImage();
    
    CvSize picSize;
    
private:
    
    CvCapture* m_cap;
    
    IplImage* m_grab;
    
    unsigned char bkgnd[CAM_WIDTH * CAM_HEIGHT * 3];
    
};

#endif
