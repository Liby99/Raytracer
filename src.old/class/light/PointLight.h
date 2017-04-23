#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light/Light.h"

using namespace std;

class PointLight : public Light {
protected:
    
    // Default Fall Off and position
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_FALL_OFF;
    
    // Basic Variables
    vec3 position;
    vec3 fallOff;
    
    // Helper method for getting brightness
    float calcBrightness(const float distance) const;
    
public:
    
    // Constructor
    PointLight();
    PointLight(const Color color);
    PointLight(const Color color, const vec3 position);
    
    // Position setter getter
    vec3 getPosition() const;
    void setPosition(const vec3 position);
    
    // Fall Off related setter getter
    vec3 getFallOff() const;
    void setFallOff(const vec3 fallOff);
    
    // Inherited brightness and tolight
    virtual float getBrightness(const Scene & scene, const Intersection & intersection) const;
    virtual vec3 getToLightDirection(const Intersection & intersection) const;
};

#endif
