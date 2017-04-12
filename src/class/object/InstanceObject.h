#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include "object/Object.h"

class InstanceObject : public Object {
protected:
    
    // Object reference
    Object * object;
    
    // Intersection method
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor
    InstanceObject();
    InstanceObject(const Object & object);
    
    // Getter and setter
    Object & getObject() const;
    void setObject(const Object & object);
};

#endif
