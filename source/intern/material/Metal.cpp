#include "material/Metal.h"

Metal::Metal() : Metal(Color::WHITE) {}

Metal::Metal(Color color) : Material() {
    setColor(color);
}

Color Metal::getColor() {
    return color;
}

void Metal::setColor(Color color) {
    this->color = color;
}

Color Metal::computeReflection(Intersection & i, Ray & out) {
    return Color::BLACK;
}

vector<pair<Ray, Color>> Metal::reflection(Intersection & intersection, int amount) {
    
    // Prepare the result
    vector<pair<Ray, Color>> result;
    
    // Calculate the reflection direction
    vec3 norm = intersection.getNormal();
    vec3 in = intersection.getRay().getDirection();
    vec3 dir = in - 2.0f * norm * dot(norm, in);
    
    // Calculate the reflection ray
    Ray reflect = Ray(intersection.getPosition(), dir);
    reflect.increment();
    
    // Push the ray and color back to result
    result.push_back(make_pair(reflect, color));
    return result;
}

Color Metal::emission() {
    return Color::BLACK;
}
