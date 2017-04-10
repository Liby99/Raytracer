#ifndef CYLINDER_H
#define CYLINDER_H

#include "object/Object.h"
#include "util/Orientable.h"

class Cylinder : public Object, public Orientable {
private:
    
    // Default values
    const static float DEFAULT_HEIGHT;
    const static float DEFAULT_RADIUS;
    
    // Basic parameters
    float height;
    float radius;
    
    // Helper methods
    bool higher(float h);
    bool lower(float h);
    bool inHeight(float h);
    
protected:
    
    // Intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructors
    Cylinder();
    Cylinder(float height, float radius);
    Cylinder(int orientation);
    Cylinder(int orientation, float height, float radius);
    
    // Basic getter and setter
    float getHeight();
    void setHeight(float height);
    float getRadius();
    void setRadius(float radius);
};

#endif
