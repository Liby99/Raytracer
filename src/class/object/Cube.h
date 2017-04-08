#ifndef CUBE_H
#define CUBE_H

#include "object/Object.h"

class Cube : public Object {
private:
    
    // Private parameters
    float width;
    float length;
    float height;
    
    // Corner getter
    vec3 getMaxCorner();
    vec3 getMinCorner();
public:
    
    // Constructor with the size of the cube
    Cube();
    Cube(float width, float height, float length);
    
    // Basic getter and setter
    float getWidth();
    void setWidth(float width);
    float getHeight();
    void setHeight(float height);
    float getLength();
    void setLength(float length);
    
    // Intersection
    bool intersect(Ray & ray, Intersection & intersection);
};

#endif
