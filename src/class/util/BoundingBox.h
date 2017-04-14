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
    void extend(const Object & object);
    void extend(const BoundingBox & box);
    
    // Check intersect
    bool intersect(const Ray & ray) const;
    bool intersect(const Object & object) const;
    bool intersect(const BoundingBox & box) const;
};

#endif
