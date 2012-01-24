//
//  VideoManager.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//
#define is_mac true


#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "VideoManager.h"

using namespace std;

VideoManager::VideoManager() {
    initVideoStream();
}

void VideoManager::initVideoStream() {
	m_cap = cvCaptureFromCAM (0);
    if (!m_cap) {
        cout << "No webcam found. Exiting.\n";
        exit(0);
    }
    capture();
}

void VideoManager::capture() {
    m_grab = cvQueryFrame(m_cap);

    if(!m_grab){
        printf("Could not query frame. Trying to reinitialize.\n");
        cvReleaseCapture (&m_cap);
        initVideoStream();
        return;
    }
    
    // isight issue
  //  if(is_mac)
//        cvConvertImage(m_grab, m_grab, CV_CVTIMG_FLIP);
   //  cvFlip(m_grab, NULL, 1);
    
    m_picSize = cvGetSize(m_grab);
}

unsigned char *VideoManager::getCameraImage()
{
    //static unsigned char bkgnd[CAM_WIDTH * CAM_HEIGHT * 3];
    
    //memcpy( bkgnd, iplbkgnd->imageData, sizeof(bkgnd) );
    

    
    for ( int i=0, j=0; i < m_grab->imageSize && j < sizeof(bkgnd); i += m_grab->widthStep, j += CAM_WIDTH * 3 )
    {
        memcpy( bkgnd+j, m_grab->imageData+i, CAM_WIDTH * 3);    
    }
    
    return bkgnd;
}