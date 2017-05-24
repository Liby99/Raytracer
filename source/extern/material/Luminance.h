#ifndef LUMINANCE_H
#define LUMINANCE_H

#include "material/Material.h"

class Luminance : public Material {
private:
    
    Color color;
    
public:
    
    Luminance();
    Luminance(Color color);
    
    Color getColor();
    void setColor(Color color);
    
    virtual Color emission();
};

#endif
