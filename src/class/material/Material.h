#ifndef MATERIAL_H
#define MATERIAL_H

#include "util/Color.h"

using namespace std;

class Scene;
class Intersection;

class Material {
protected:
    
    // Default
    static float DEFAULT_OPACITY;
    
    // Opacity parameter
    float opacity;
    
    // Get shading color to be inherited by subclasses
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) const;
    
public:
    
    // Constructor
    Material();
    
    // Getter and setter
    void setOpacity(float opacity);
    float getOpacity() const;
    Color shade(Scene & scene, Intersection & intersection) const;
};

#endif
