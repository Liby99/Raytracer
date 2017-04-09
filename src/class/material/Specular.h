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
    
public:
    
    // Constructor
    Specular(Color specular);
    Specular(Color specular, float shininess);
    
    Color getSpecular();
    void setSpecular(Color color);
    float getShininess();
    void setShininess(float shininess);
    
    // Shading
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
