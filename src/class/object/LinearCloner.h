#ifndef LINEAR_CLONER_H
#define LINEAR_CLONER_H

#include "object/Cloner.h"

class LinearCloner : public Cloner {
protected:
    
    const static vec3 DEFAULT_GAP;
    const static unsigned int DEFAULT_COUNT;
    
    // Basic parameters
    vec3 gap;
    unsigned int count;
    
    // Update the intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual void updateCache();
    
    void updateGap();
    
public:
    
    // Constructors
    LinearCloner();
    LinearCloner(Object & object);
    LinearCloner(Object & object, vec3 gap, unsigned int count);
    
    // Getter and setters
    vec3 getGap();
    void setGap(vec3 gap);
    unsigned int getCount();
    void setCount(unsigned int count);
};

#endif
