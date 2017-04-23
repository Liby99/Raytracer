#ifndef LIGHT_H
#define LIGHT_H

#include "util/Transform.h"
#include "util/Color.h"
#include "util/Ray.h"
#include "util/Intersection.h"

using namespace std;

class Scene;

class Light {
protected:
    
    const static Color DEFAULT_COLOR;
    const static float DEFAULT_INTENSITY;
    const static bool DEFAULT_CAST_SHADOW;
    
    // Private color
    Color color;
    float intensity;
    bool castShadow;
    
public:
    
    // Constructor
    Light();
    Light(const Color c);
    
    // Color related setter getter
    Color getColor() const;
    void setColor(const Color color);
    float getIntensity() const;
    void setIntensity(const float intensity);
    bool getCastShadow() const;
    void setCastShadow(const bool castShadow);
    
    // Illuminate
    virtual float getBrightness(const Scene & scene, const Intersection & intersection) const;
    virtual vec3 getToLightDirection(const Intersection & intersection) const;
};

#endif
