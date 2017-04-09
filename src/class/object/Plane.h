#ifndef PLANE_H
#define PLANE_H

#include "object/Object.h"

class Plane : public Object {
private:
    
    const static vec3 NORMALS[6];
    const static int DEFAULT_ORIENTATION;
    
    // Private parameters
    int orientation;
    
protected:
    
    // Inherited update intersection
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Const static of orientation
    const static int X_POSITIVE = 0;
    const static int X_NEGATIVE = 1;
    const static int Y_POSITIVE = 2;
    const static int Y_NEGATIVE = 3;
    const static int Z_POSITIVE = 4;
    const static int Z_NEGATIVE = 5;
    
    // Constructor
    Plane();
    Plane(int orientation);
    
    // Basic getter and setter
    int getOrientation();
    void setOrientation(int orientation);
};

#endif
