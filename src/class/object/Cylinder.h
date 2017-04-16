#ifndef CYLINDER_H
#define CYLINDER_H

#include "object/Object.h"
#include "util/Orientable.h"

class Cylinder : public Object, public Boundable, public Orientable {
private:
    
    // Default values
    const static float DEFAULT_HEIGHT;
    const static float DEFAULT_RADIUS;
    
    // Basic parameters
    float height;
    float radius;
    
    // Helper methods
    bool higher(const float h) const;
    bool lower(const float h) const;
    bool inHeight(const float h) const;
    
protected:
    
    // Intersection
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    virtual vector<vec3> getBoundingVertices() const;
    
public:
    
    // Constructors
    Cylinder();
    Cylinder(const float height, float radius);
    Cylinder(const int orientation);
    Cylinder(const int orientation, const float height, const float radius);
    
    // Basic getter and setter
    float getHeight() const;
    void setHeight(const float height);
    float getRadius() const;
    void setRadius(const float radius);
};

#endif
