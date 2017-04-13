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
    vec3 getMaxCorner() const;
    vec3 getMinCorner() const;
    
    // Intersection
    bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor with the size of the cube
    Cube();
    Cube(const float width, const float height, const float length);
    
    // Basic getter and setter
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    virtual void setWidth(const float width);
    virtual void setHeight(const float height);
    virtual void setLength(const float length);
};

#endif
