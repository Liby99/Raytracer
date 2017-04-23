#ifndef SPECULAR_H
#define SPECULAR_H

#include "material/Material.h"

using namespace std;

class Specular : public Material {
private:
    
    static Color DEFAULT_SPECULAR;
    static float DEFAULT_SHININESS;
    
    // Basic parameters
    Color specular;
    float shininess;
    
    // Shading
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) const;
    
public:
    
    // Constructor
    Specular();
    Specular(Color specular);
    Specular(Color specular, float shininess);
    
    Color getSpecular() const;
    void setSpecular(Color color);
    float getShininess() const;
    void setShininess(float shininess);
};

#endif
