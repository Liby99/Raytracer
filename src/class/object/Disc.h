#ifndef DISC_H
#define DISC_H

#include "object/Object.h"
#include "util/Orientable.h"

class Disc : public Object, public Orientable {
protected:
    
    // Default values
    const static float DEFAULT_RADIUS;
    
    // Radius
    float radius;
    
    // Intersect
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructors
    Disc();
    Disc(float radius);
    Disc(float radius, int orientation);
    
    // Getter and setter
    float getRadius();
    void setRadius(float radius);
};

#endif
