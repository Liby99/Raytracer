#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include "object/Object.h"

class InstanceObject : public Object, public Boundable {
protected:
    
    // Object reference
    const Object * object;
    
    // Intersection method
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    
public:
    
    // Constructor
    InstanceObject();
    InstanceObject(const Object & object);
    
    // Getter and setter
    const Object & getObject() const;
    void setObject(const Object & object);
};

#endif
