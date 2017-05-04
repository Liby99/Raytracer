#ifndef SCENE_H
#define SCENE_H

#include "util/Color.h"
#include "util/Ray.h"
#include "util/Intersection.h"
#include "object/Object.h"
#include "material/Material.h"
#include "light/Light.h"

class Scene {
protected:
    
    // Global Variables
    Color background;
    vector<Object *> objects;
    vector<Light *> lights;
    
public:
    
    // Constructor and Destructors
    Scene();
    
    // Background
    Color getBackgroundColor();
    void setBackgroundColor(Color color);
    
    // Light related getter and setter
    unsigned int lightAmount();
    Light & getLight(int i);
    virtual void addLight(Light & light);
    
    // Object related getter and setter
    unsigned int objectAmount();
    Object & getObject(int i);
    virtual void addObject(Object & object);
    
    // Intersection
    virtual bool getIntersection(Ray & ray, Intersection & intersection);
    virtual Color getIntersectionColor(Intersection & intersection);
    virtual Color getRayColor(Ray & ray);
};

#endif