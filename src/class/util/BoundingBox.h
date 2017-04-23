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
    BoundingBox(Object * obj);
    BoundingBox(vector<Object *> objs);
    
    // Basic getter
    vec3 getMinCorner();
    vec3 getMaxCorner();
    
    // Basic setter
    void setMinCorner(vec3 minCorner);
    void setMaxCorner(vec3 maxCorner);
    
    // Extend the box to a new bound
    void extend(Object & object);
    void extend(BoundingBox & box);
    
    // Check intersect
    bool intersect(vec3 vec);
    bool intersect(Ray & ray);
    bool intersect(Ray & ray, float & t);
    bool intersect(Object & object);
    bool intersect(BoundingBox & box);
};

#endif
