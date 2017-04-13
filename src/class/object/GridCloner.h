#ifndef GRID_CLONER_H
#define GRID_CLONER_H

#include "object/Cloner.h"

class GridCloner : public Cloner {
protected:
    
    // Constant
    const static float DEFAULT_SIZE;
    const static unsigned int DEFAULT_COUNT;
    
    float width;
    float height;
    float length;
    unsigned int xCount;
    unsigned int yCount;
    unsigned int zCount;
    
    //
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual void updateCache();
    void updateSize();
    
public:
    
    //
    GridCloner();
    GridCloner(const Object & object);
    
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    void setWidth(const float width);
    void setHeight(const float height);
    void setLength(const float length);
    
    unsigned int getXCount() const;
    unsigned int getYCount() const;
    unsigned int getZCount() const;
    void setXCount(const unsigned int xCount);
    void setYCount(const unsigned int yCount);
    void setZCount(const unsigned int zCount);
};

#endif
