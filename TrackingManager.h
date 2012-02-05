//
//  TrackingManager.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#ifndef VirtualMarbleGame_Tracking_h
#define VirtualMarbleGame_Tracking_h

// Apple iSight: 54.3
#define CAM_ANGLE 62

#ifdef __linux
#include <GL/gl.h>
#include <GL/freeglut.h>
#else
#include <opengl/OpenGL.h>
#include <GLUT/glut.h>
#endif

#include <iostream>
#include <opencv2/opencv.hpp>

#include "VideoManager.h"
#include "Pose.h"
#include "PoseEstimation.h"

using namespace std;

class VideoManager;
class Pose;

class TrackingManager {
    
public:
    
    TrackingManager(bool debug, VideoManager* videoManager, Pose* pose, Pose* gravity);
    ~TrackingManager();
    void process();
    void init();
    void switchCalibrate();
    
private:
    
    VideoManager* m_videoManager;
    Pose* m_pose;
    Pose* m_gravity;
    bool m_debug;
    bool m_calibrate;
    
};

#endif
