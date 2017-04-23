#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "util/Ray.h"

class Object;

class BoundingBox {
private:
    
    // Basic parameters
    bool initiated;
    vec3 minCorner;
    vec3 maxCorner;
    
public:
    
    // Constructor
    BoundingBox();
    BoundingBox(vec3 minCorner, vec3 maxCorner);
    
    // Basic getter
    vec3 getMinCorner() const;
    vec3 getMaxCorner() const;
    
    // Basic setter
    void setMinCorner(vec3 minCorner);
    void setMaxCorner(vec3 maxCorner);
    
    // Extend the box to a new bound
    void extend(Object & object);
    void extend(BoundingBox & box);
    
    // Check intersect
    bool intersect(Ray & ray) const;
    bool intersect(Object & object) const;
    bool intersect(BoundingBox & box) const;
};

#endif
