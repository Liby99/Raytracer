#ifndef CLONER_H
#define CLONER_H

#include "object/InstanceObject.h"

class Cloner : public Object {
protected:
    
    Object * object;
    vector<InstanceObject *> instances;
    
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual vec3 sampleSurfacePointHelper(float t);
    
public:
    
    Cloner(Object & object);
};

#endif
