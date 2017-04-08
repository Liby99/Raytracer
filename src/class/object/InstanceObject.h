#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include "object/Object.h"

class InstanceObject : public Object {
private:
    Object * object;
protected:
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
public:
    InstanceObject(Object & object);
    Object & getObject();
    void setObject(Object & object);
};

#endif
