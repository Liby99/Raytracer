#ifndef SCENE_H
#define SCENE_H

#include "util/Color.h"
#include "util/Ray.h"
#include "util/Intersection.h"
#include "object/Object.h"
#include "material/Material.h"
#include "light/Light.h"

class Scene {
private:
    
    // Global Variables
    Color background;
    vector<Object *> objects;
    vector<Light *> lights;
    
    // Helper methods
    bool getIntersection(Ray & ray, Intersection & intersection);
    Color getIntersectionColor(Intersection & intersection);
    
public:
    
    // Constructor and Destructors
    Scene();
    
    Color getBackgroundColor();
    void setBackgroundColor(Color & color);
    
    //
    unsigned int lightAmount();
    Light & getLight(int i);
    void addLight(Light & light);
    
    //
    unsigned int objectAmount();
    Object & getObject(int i);
    void addObject(Object & object);
    
    // Intersection
    Color getRayColor(Ray & ray);
};

#endif
