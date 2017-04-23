#ifndef REFLECTION_H
#define REFLECTION_H

#include "material/Material.h"

class Reflection : public Material {
private:
    
    // Default attenuation
    static Color DEFAULT_TINT;
    static float DEFAULT_ATTENUATION;
    
    // Tint of reflectance color
    Color tint;
    float attenuation;
    
    // Shading
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) ;
    
public:
    
    // Constructor
    Reflection();
    Reflection(Color tint);
    
    // Basic getter and setter
    Color getTint() ;
    void setTint(Color color);
    float getAttenuation() ;
    void setAttenuation(float attenuation);
};

#endif
