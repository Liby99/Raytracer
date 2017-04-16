#ifndef DISC_H
#define DISC_H

#include "object/Object.h"
#include "util/Orientable.h"

class Disc : public Object, public Boundable, public Orientable {
protected:
    
    // Default values
    const static float DEFAULT_RADIUS;
    
    // Radius
    float radius;
    
    // Intersect
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    
public:
    
    // Constructors
    Disc();
    Disc(const float radius);
    Disc(const float radius, const int orientation);
    
    // Getter and setter
    float getRadius() const;
    void setRadius(const float radius);
};

#endif
