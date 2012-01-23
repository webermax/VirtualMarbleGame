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
#define CAM_ANGLE 35

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

class VideoManager {
    
public:
    
    VideoManager();
    
    ~VideoManager();
    
    void initVideoStream();
    
    unsigned char *getCameraImage();
    
    void capture();
    
    IplImage* getThresholdImage();
    
private:
    
    CvCapture* m_cap;
    
    IplImage* m_grab;
    
    CvSize m_picSize;
    
    unsigned char bkgnd[CAM_WIDTH * CAM_HEIGHT * 3];
    
};

#endif
