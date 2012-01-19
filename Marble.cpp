//
//  Marble.cpp
//  VirtualMarbleGame
//
//  Created by Maximilian Weber
//

#include "Marble.h"

Marble::Marble(float x, float y, float z, float radius, float weight) {
    m_x = x;
    m_y = y;
    m_z = z;
    m_radius = radius;
    m_weight = weight;
}

float Marble::getX() {
    return m_x;
}

float Marble::getY() {
    return m_y;
}

float Marble::getZ() {
    return m_z;
}

float Marble::getRadius() {
    return m_radius;
}

float Marble::getWeight() {
    return m_weight;
}

void Marble::setX(float x) {
    m_x = x;
}

void Marble::setY(float y) {
    m_y = y;
}

void Marble::setZ(float z) {
    m_z = z;
}

void Marble::translateX(float x) {
    m_x += x;
}

void Marble::translateY(float y) {
    m_y += y;
}

void Marble::translateZ(float z) {
    m_z += z;
}

void Marble::setRadius(float radius) {
    m_radius = radius;
}

void Marble::setWeight(float weight) {
    m_weight = weight;
}