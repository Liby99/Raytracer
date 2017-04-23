#ifndef CUBE_H
#define CUBE_H

#include "object/Object.h"

class Cube : public Object {
protected:
    
    static float DEFAULT_SIZE;
    
    // Private parameters
    float width;
    float length;
    float height;
    
    // Corner getter
    vec3 getMaxCorner() const;
    vec3 getMinCorner() const;
    
    // Intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor with the size of the cube
    Cube();
    Cube(float width, float height, float length);
    
    // Basic getter and setter
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    virtual void setWidth(float width);
    virtual void setHeight(float height);
    virtual void setLength(float length);
};

#endif
