#ifndef PLANE_H
#define PLANE_H

#include "object/Object.h"
#include "util/Orientable.h"

class Plane : public Object, public Orientable {
protected:
    
    // Inherited update intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructor
    Plane();
    Plane(int orientation);
};

#endif
