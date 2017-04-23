#ifndef AMBIENT_H
#define AMBIENT_H

#include "material/Material.h"

class Ambient : public Material {
protected:
    
    // Default Ambient Color
    static Color DEFAULT_AMBIENT;
    
    // Ambient color
    Color ambient;
    
    // Get shading method
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) const;
    
public:
    
    // Constructors
    Ambient();
    Ambient(Color ambient);
    
    // Getter and setter
    Color getAmbient() const;
    void setAmbient(Color ambient);
};

#endif
