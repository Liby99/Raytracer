#ifndef REFLECTION_H
#define REFLECTION_H

#include "material/Material.h"

class Reflection : public Material {
private:
    
    // Default attenuation
    const static Color DEFAULT_TINT;
    const static float DEFAULT_ATTENUATION;
    
    // Tint of reflectance color
    Color tint;
    float attenuation;
    
    // Shading
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
    
public:
    
    // Constructor
    Reflection();
    Reflection(const Color tint);
    
    // Basic getter and setter
    Color getTint() const;
    void setTint(const Color color);
    float getAttenuation() const;
    void setAttenuation(const float attenuation);
};

#endif
