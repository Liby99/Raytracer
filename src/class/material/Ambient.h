#ifndef AMBIENT_H
#define AMBIENT_H

#include "material/Material.h"

class Ambient : public Material {
protected:
    
    // Default Ambient Color
    const static Color DEFAULT_AMBIENT;
    
    // Ambient color
    Color ambient;
    
    // Get shading method
    virtual Color getShadingColor(Scene & scene, Intersection & intersection);
    
public:
    
    // Constructors
    Ambient();
    Ambient(Color ambient);
    
    // Getter and setter
    Color getAmbient();
    void setAmbient(Color ambient);
};

#endif
