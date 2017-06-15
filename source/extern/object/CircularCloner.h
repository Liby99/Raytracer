#ifndef CIRCULAR_CLONER_H
#define CIRCULAR_CLONER_H

#include "object/Cloner.h"

class CircularCloner : public Cloner {
protected:
    
    float radius;
    int count;
    
    void retransform();
    void reconstruct();
    
public:
    
    CircularCloner(Object & object);
    CircularCloner(Object & object, float radius, int count);
    
    float getRadius();
    void setRadius(float radius);
    
    int getCount();
    void setCount(int count);
};

#endif
