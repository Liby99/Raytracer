#ifndef CLONER_H
#define CLONER_H

#include "object/InstanceObject.h"

class Cloner : public InstanceObject, public Boundable {
protected:
    
    // Object
    vector<InstanceObject> cache;
    
    // Update Intersection
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    virtual void updateCache();
    
public:
    
    // Constructor
    Cloner();
    Cloner(const Object & object);
};

#endif
