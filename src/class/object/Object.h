#ifndef OBJECT_H
#define OBJECT_H

#include "util/Transform.h"
#include "util/Ray.h"
#include "util/Intersection.h"
#include "material/Material.h"

#include <vector>

class Object {
protected:
    
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_SCALER;
    const static vec3 DEFAULT_ROTATION;
    
    // Materials
    vector<Material *> materials;
    
    // Transform properties
    vec3 position;
    vec3 scaler;
    vec3 rotation;
    
    // Get transformation helper method
    mat4 getTransformMatrix();
    
public:
    
    // Constructor
    Object();
    
    // Material Related
    int materialAmount();
    Material & getMaterial(int i);
    void addMaterial(Material & material);
    
    // Rotate Transformation
    void rotate(vec3 rotation);
    void rotateX(float degX);
    void rotateY(float degY);
    void rotateZ(float degZ);
    
    // Translate Transformation
    void translate(vec3 position);
    void translateX(float x);
    void translateY(float y);
    void translateZ(float z);
    
    // Scale Transformation
    void scale(vec3 scaler);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    
    virtual bool intersect(Ray & ray, Intersection & intersection);
};

#endif
