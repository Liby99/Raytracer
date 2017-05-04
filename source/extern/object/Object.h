#ifndef OBJECT_H
#define OBJECT_H

#include "util/Transform.h"
#include "util/Ray.h"
#include "util/Intersection.h"
#include "util/BoundingBox.h"
#include "material/Material.h"

#include <vector>

class Object {
protected:
    
    // Default Values
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_SCALER;
    const static vec3 DEFAULT_ROTATION;
    
    // Materials
    Material * material;
    
    // Transform properties
    bool transformed;
    vec3 position;
    vec3 scaler;
    vec3 rotation;
    
    // Virtual Functions
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual vector<vec3> getBoundingVertices();
    
public:
    
    // Constructor
    Object();
    
    // Material Related
    Material & getMaterial();
    void setMaterial(Material & material);
    
    // Boundable setting
    bool isBoundable();
    void setBoundable(bool boundable);
    
    // Basic Getter
    vec3 getRotation();
    vec3 getScale();
    vec3 getPosition();
    
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
    
    BoundingBox getBoundingBox();
    
    // Virtaul intersect method
    bool intersect(Ray & ray, Intersection & intersection);
};

#endif
