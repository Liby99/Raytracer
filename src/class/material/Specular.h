#ifndef SPECULAR_H
#define SPECULAR_H

#include "material/Material.h"

using namespace std;

class Specular : public Material {
private:
    
    const static float DEFAULT_SHININESS;
    
    // Basic parameters
    Color specular;
    float shininess;
    
    // Shading
    virtual Color getShadingColor(Scene & scene, Intersection & intersection);
    
public:
    
    // Constructor
    Specular(Color specular);
    Specular(Color specular, float shininess);
    
    Color getSpecular();
    void setSpecular(Color color);
    float getShininess();
    void setShininess(float shininess);
};

#endif
