//
//  Marble.h
//  VirtualMarbleGame
//
//  Created by Maximilian Weber on 14/01/2012.
//

#ifndef VirtualMarbleGame_Marble_h
#define VirtualMarbleGame_Marble_h

class Marble {
    
public:
    
    Marble(float x, float y, float z, float radius, float weight);
    
    float getRadius();
    
    float getWeight();
    
    float getX();
    
    float getY();
    
    float getZ();
    
    void setRadius(float radius);
    
    void setWeight(float weight);
    
    void setX(float x);
    
    void setY(float y);
    
    void setZ(float z);
    
    void translateX(float x);
    
    void translateY(float y);
    
    void translateZ(float z);
    
public:
    
    float m_x;
    
    float m_y;
    
    float m_z;
    
    
    float s_x;
    
    float s_y;
    
    float s_z;
 
    
    float v_x;
    
    float v_y;
    
    float v_z;
    
    
    float m_weight;
    
    float m_radius;
    
};

#endif
