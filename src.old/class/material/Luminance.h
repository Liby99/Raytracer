#ifndef LUMINANCE_H
#define LUMINANCE_H

#include "material/Material.h"

class Luminance : public Material {
protected:
    
    // Default color
    const static Color DEFAULT_COLOR;
    
    // Basic Color
    Color color;
    
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
    
public:
    
    // Constructors
    Luminance();
    Luminance(const Color color);
    
    //
    Color getColor() const;
    void setColor(const Color color);
};

#endif
