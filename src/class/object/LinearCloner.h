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
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    virtual void updateCache();
    void updateGap();
    
public:
    
    // Constructors
    LinearCloner();
    LinearCloner(const Object & object);
    LinearCloner(const Object & object, const vec3 gap, const unsigned int count);
    
    // Getter and setters
    vec3 getGap() const;
    void setGap(const vec3 gap);
    unsigned int getCount() const;
    void setCount(const unsigned int count);
};

#endif
