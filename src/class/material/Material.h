#ifndef MATERIAL_H
#define MATERIAL_H

#include "util/Color.h"

using namespace std;

class Scene;
class Intersection;

class Material {
protected:
    
    // Default
    const static float DEFAULT_OPACITY;
    
    // Opacity parameter
    float opacity;
    
    // Get shading color to be inherited by subclasses
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
    
public:
    
    // Constructor
    Material();
    
    // Getter and setter
    void setOpacity(const float opacity);
    float getOpacity() const;
    Color shade(const Scene & scene, const Intersection & intersection);
};

#endif
