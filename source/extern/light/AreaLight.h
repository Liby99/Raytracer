#ifndef AREA_LIGHT_H
#define AREA_LIGHT_H

#include "material/Luminance.h"
#include "light/PointLight.h"
#include "object/Object.h"
#include "util/Orientable.h"
#include "util/Sampler.h"

class AreaLight : public Light, public Object, public Orientable {
private:
    
    using Object::setMaterial;
    
protected:
    
    // Default constants
    const static float DEFAULT_WIDTH;
    const static float DEFAULT_HEIGHT;
    
    Luminance * lum;
    
    // Size parameters
    float width;
    float height;
    vec3 fallOff;
    
    int samplingMethod;
    int weightingMethod;
    
    // Helper method
    float calcBrightness(float distance);
    
    // Object inherited
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual vector<vec3> getBoundingVertices();
    
public:
    
    AreaLight();
    AreaLight(Color color, float width, float height, int orientation);
    AreaLight(float width, float height);
    ~AreaLight();
    
    virtual void setColor(Color color);
    virtual bool hasMaterial();
    virtual Material & getMaterial();
    
    float getWidth();
    float getHeight();
    void setWidth(float width);
    void setHeight(float height);
    vec3 getFallOff();
    void setFallOff(vec3 fallOff);
    
    void setSamplingMethod(int samplingMethod);
    void setWeightingMethod(int weightingMethod);
    
    virtual float getBrightness(Scene & scene, Intersection & intersection, Ray & ray, float t);
    virtual vector<vec3> getToLightDirection(Intersection & intersection, int sampleAmount, float t);
};

#endif
