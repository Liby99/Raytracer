#include "scene/Scene.h"

Scene::Scene() {
    
}

Color Scene::getBackgroundColor() const {
    return background;
}

void Scene::setBackgroundColor(const Color color) {
    this->background = color;
}

unsigned int Scene::lightAmount() const {
    return lights.size();
}

Light & Scene::getLight(int i) const {
    return *(lights[i]);
}

void Scene::addLight(Light & light) {
    lights.push_back(&light);
}

unsigned int Scene::objectAmount() const {
    return objects.size();
}

Object & Scene::getObject(int i) const {
    return *(objects[i]);
}

void Scene::addObject(Object & object) {
    objects.push_back(&object);
}

bool Scene::getIntersection(const Ray & ray, Intersection & intersection) const {
    bool hit = false;
    #pragma omp parallel for
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->intersect(ray, intersection)) {
            hit = true;
        }
    }
    return hit;
}

Color Scene::getIntersectionColor(const Intersection & intersection) const {
    Color color;
    const Object & obj = intersection.getObject();
    #pragma omp parallel for
    for (int i = 0; i < obj.materialAmount(); i++) {
        color += obj.getMaterial(i).shade(*this, intersection);
    }
    return color;
}

Color Scene::getRayColor(const Ray & ray) const {
    Intersection intersection = Intersection(ray);
    if (getIntersection(ray, intersection)) {
        return getIntersectionColor(intersection);
    }
    else {
        return background;
    }
}
