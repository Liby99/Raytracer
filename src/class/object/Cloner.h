#ifndef CLONER_H
#define CLONER_H

#include "object/InstanceObject.h"

class Cloner : public InstanceObject {
protected:
    
    // Object
    vector<InstanceObject> cache;
    
    // Update Intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual void updateCache();
    
public:
    
    // Constructor
    Cloner();
    Cloner(Object & object);
};

#endif
