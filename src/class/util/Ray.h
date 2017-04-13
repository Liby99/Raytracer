#ifndef RAY_H
#define RAY_H

#include "util/Transform.h"

class Ray {
private:
    
    // Constants
    const static float INCREMENT;
    
    // Basic Ray Parameter
    vec3 origin;
    vec3 direction;
    int depth;
    bool inside;
    
public:

    // Static Max Depth Constraint
    static int maxDepth;
    
    // Constructors
    Ray();
    Ray(vec3 origin, vec3 direction);
    Ray(vec3 origin, vec3 direction, int depth);
    Ray(vec3 origin, vec3 direction, int depth, bool inside);
    
    // Setter
    vec3 getOrigin() const;
    void setOrigin(vec3 origin);
    vec3 getDirection() const;
    void setDirection(vec3 direction);
    int getDepth() const;
    void setDepth(int depth);
    bool isInside() const;
    void setInside(bool inside);
    
    vec3 getPoint(float t) const;
    
    void increment();
    void increment(vec3 direction);
    
    bool canRecurse() const;
    
    // Transform
    Ray transform(mat4 transf) const;
    Ray inverseTransform(mat4 transf) const;
    
    // Static getter and setter
    static int getMaxDepth();
    static void setMaxDepth(int maxDepth);
};

#endif
