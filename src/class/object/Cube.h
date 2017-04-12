#ifndef CUBE_H
#define CUBE_H

#include "object/Object.h"

class Cube : public Object {
protected:
    
    const static float DEFAULT_SIZE;
    
    // Private parameters
    float width;
    float length;
    float height;
    
    // Corner getter
    vec3 getMaxCorner();
    vec3 getMinCorner();
    
    // Intersection
    bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructor with the size of the cube
    Cube();
    Cube(float width, float height, float length);
    
    // Basic getter and setter
    float getWidth();
    float getHeight();
    float getLength();
    virtual void setWidth(float width);
    virtual void setHeight(float height);
    virtual void setLength(float length);
};

#endif
