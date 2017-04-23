#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include "object/Object.h"

class InstanceObject : public Object {
protected:
    
    // Object reference
    Object * object;
    
    // Intersection method
    virtual bool updateIntersect(Ray & ray, Intersection & intersection) ;
    
public:
    
    // Constructor
    InstanceObject();
    InstanceObject(Object & object);
    
    // Getter and setter
    Object & getObject() ;
    void setObject(Object & object);
};

#endif
