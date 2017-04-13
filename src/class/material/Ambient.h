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
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
    
public:
    
    // Constructors
    Ambient();
    Ambient(const Color ambient);
    
    // Getter and setter
    Color getAmbient() const;
    void setAmbient(const Color ambient);
};

#endif
