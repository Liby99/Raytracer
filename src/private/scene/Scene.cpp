#include "scene/Scene.h"

Scene::Scene() {
    
}

Color Scene::getBackgroundColor() {
    return background;
}

void Scene::setBackgroundColor(Color color) {
    this->background = color;
}

unsigned int Scene::lightAmount() {
    return lights.size();
}

Light & Scene::getLight(int i) {
    return *(lights[i]);
}

void Scene::addLight(Light & light) {
    lights.push_back(&light);
}

unsigned int Scene::objectAmount() {
    return objects.size();
}

Object & Scene::getObject(int i) {
    return *(objects[i]);
}

void Scene::addObject(Object & object) {
    objects.push_back(&object);
}

bool Scene::getIntersection(Ray & ray, Intersection & intersection) {
    bool hit = false;
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->intersect(ray, intersection)) {
            hit = true;
        }
    }
    return hit;
}

Color Scene::getIntersectionColor(Intersection & intersection) {
    Color color;
    Object & obj = intersection.getObject();
    for (int i = 0; i < obj.materialAmount(); i++) {
        color += obj.getMaterial(i).shade(*this, intersection);
    }
    return color;
}

Color Scene::getRayColor(Ray & ray) {
    Intersection intersection = Intersection(ray);
    if (getIntersection(ray, intersection)) {
        return getIntersectionColor(intersection);
    }
    else {
        return background;
    }
}
