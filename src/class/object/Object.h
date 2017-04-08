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
    
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructor
    Object();
    
    // Material Related
    int materialAmount();
    Material & getMaterial(int i);
    void addMaterial(Material & material);
    
    // Rotate Transformation
    void setRotate(vec3 rotation);
    void rotate(vec3 rotation);
    void rotateX(float degX);
    void rotateY(float degY);
    void rotateZ(float degZ);
    
    // Translate Transformation
    void setTranslate(vec3 rotation);
    void translate(vec3 position);
    void translateX(float x);
    void translateY(float y);
    void translateZ(float z);
    
    // Scale Transformation
    void setScale(vec3 scaler);
    void scale(vec3 scaler);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    
    // Get transformation helper method
    mat4 getTransformMatrix();
    
    // Virtaul intersect method
    bool intersect(Ray & ray, Intersection & intersection);
};

#endif
