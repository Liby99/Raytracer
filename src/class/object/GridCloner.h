#ifndef GRID_CLONER_H
#define GRID_CLONER_H

#include "object/Cloner.h"

class GridCloner : public Cloner {
protected:
    
    // Constant
    const static float DEFAULT_SIZE;
    const static unsigned int DEFAULT_COUNT
    
    float width;
    float height;
    float length;
    unsigned int xCount;
    unsigned int yCount;
    unsigned int zCount;
    
    //
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual void updateCache();
    void updateSize();
    
public:
    
    //
    GridCloner();
    GridCloner(Object & object);
    
    float getWidth();
    float getHeight();
    float getLength();
    void setWidth(float width);
    void setHeight(float height);
    void setLength(float length);
    
    unsigned int getXCount();
    unsigned int getYCount();
    unsigned int getZCount();
    void setXCount(unsigned int xCount);
    void setYCount(unsigned int yCount);
    void setZCount(unsigned int zCount);
};

#endif
