#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light/PointLight.h"

using namespace std;

class SpotLight : public PointLight {
protected:
    
    // Constant default value
    const static vec3 DEFAULT_FALL_OFF;
    const static vec3 DEFAULT_TARGET;
    const static float DEFAULT_ANGLE;
    
    //
    vec3 target;
    float angle;
    
public:
    
    // Constructors
    SpotLight();
    SpotLight(const Color color, const vec3 position, const vec3 target, const float angle);
    
    // Basic getter and setter
    vec3 getPosition() const;
    void setPosition(const vec3 position);
    vec3 getTarget() const;
    void setTarget(const vec3 target);
    float getAngle() const;
    void setAngle(const float angle);
    
    // Illuminate
    virtual float getBrightness(const Scene & scene, const Intersection & intersection) const;
    virtual vec3 getToLightDirection(const Intersection & intersection) const;
};

#endif
