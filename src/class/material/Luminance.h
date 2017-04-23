#ifndef LUMINANCE_H
#define LUMINANCE_H

#include "material/Material.h"

class Luminance : public Material {
protected:
    
    // Default color
    static Color DEFAULT_COLOR;
    
    // Basic Color
    Color color;
    
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) const;
    
public:
    
    // Constructors
    Luminance();
    Luminance(Color color);
    
    //
    Color getColor() const;
    void setColor(Color color);
};

#endif
