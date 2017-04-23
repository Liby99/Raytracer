#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light/Light.h"

using namespace std;

class PointLight : public Light {
protected:
    
    // Default Fall Off and position
    static vec3 DEFAULT_POSITION;
    static vec3 DEFAULT_FALL_OFF;
    
    // Basic Variables
    vec3 position;
    vec3 fallOff;
    
    // Helper method for getting brightness
    float calcBrightness(float distance) const;
    
public:
    
    // Constructor
    PointLight();
    PointLight(Color color);
    PointLight(Color color, vec3 position);
    
    // Position setter getter
    vec3 getPosition() const;
    void setPosition(vec3 position);
    
    // Fall Off related setter getter
    vec3 getFallOff() const;
    void setFallOff(vec3 fallOff);
    
    // Inherited brightness and tolight
    virtual float getBrightness(Scene & scene, Intersection & intersection) const;
    virtual vec3 getToLightDirection(Intersection & intersection) const;
};

#endif
