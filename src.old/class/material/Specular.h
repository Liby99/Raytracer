#ifndef SPECULAR_H
#define SPECULAR_H

#include "material/Material.h"

using namespace std;

class Specular : public Material {
private:
    
    const static Color DEFAULT_SPECULAR;
    const static float DEFAULT_SHININESS;
    
    // Basic parameters
    Color specular;
    float shininess;
    
    // Shading
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
    
public:
    
    // Constructor
    Specular();
    Specular(const Color specular);
    Specular(const Color specular, const float shininess);
    
    Color getSpecular() const;
    void setSpecular(const Color color);
    float getShininess() const;
    void setShininess(const float shininess);
};

#endif
