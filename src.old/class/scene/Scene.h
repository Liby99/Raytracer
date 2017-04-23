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
    Color getBackgroundColor() const;
    void setBackgroundColor(const Color color);
    
    // Light related getter and setter
    unsigned int lightAmount() const;
    Light & getLight(int i) const;
    void addLight(Light & light);
    
    // Object related getter and setter
    unsigned int objectAmount() const;
    Object & getObject(int i) const;
    void addObject(Object & object);
    
    // Intersection
    bool getIntersection(const Ray & ray, Intersection & intersection) const;
    Color getIntersectionColor(const Intersection & intersection) const;
    Color getRayColor(const Ray & ray) const;
};

#endif
