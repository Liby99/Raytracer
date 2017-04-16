#ifndef PLANE_H
#define PLANE_H

#include "object/Object.h"
#include "util/Orientable.h"

class Plane : public Object, public Orientable {
protected:
    
    // Inherited update intersection
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    
public:
    
    // Constructor
    Plane();
    Plane(const int orientation);
};

#endif
