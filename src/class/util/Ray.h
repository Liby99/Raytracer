#ifndef RAY_H
#define RAY_H

#include "util/Transform.h"

class Ray {
private:
    
    static int maxDepth;
    
    //
    vec3 origin;
    vec3 direction;
    int depth;
    bool inside;
    
public:
    
    // Constructors
    Ray();
    Ray(vec3 origin, vec3 direction);
    Ray(vec3 origin, vec3 direction, int depth);
    Ray(vec3 origin, vec3 direction, int depth, bool inside);
    
    // Setter
    vec3 getOrigin();
    void setOrigin(vec3 origin);
    vec3 getDirection();
    void setDirection(vec3 direction);
    int getDepth();
    void setDepth(int depth);
    bool isInside();
    void setInside();
    
    // Transform
    Ray inverseTransform(mat4 transf);
    
    // Static getter and setter
    static int getMaxDepth();
    static void setMaxDepth(int maxDepth);
};

#endif
