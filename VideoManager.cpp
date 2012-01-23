//
//  VideoManager.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include <iostream>
#include <iomanip>

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
}

void VideoManager::capture() {
    m_grab = cvQueryFrame(m_cap);

    if(!m_grab){
        printf("Could not query frame. Trying to reinitialize.\n");
        cvReleaseCapture (&m_cap);
        initVideoStream();
        return;
    }

    m_picSize = cvGetSize(m_grab);
}

unsigned char *VideoManager::getCameraImage() {
    static unsigned char bkgnd[CAM_WIDTH * CAM_HEIGHT * 3];
    
    // isight issue
    IplImage* iplbkgnd = cvCreateImage(m_picSize, IPL_DEPTH_8U, 3);
    cvCvtColor(m_grab, iplbkgnd, CV_BGR2RGB);
    
    memcpy( bkgnd, iplbkgnd->imageData, sizeof(bkgnd) );
    return bkgnd;
}