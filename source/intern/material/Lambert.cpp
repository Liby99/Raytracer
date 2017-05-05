#include "material/Lambert.h"

Lambert::Lambert() : Lambert(Color::WHITE) {}

Lambert::Lambert(Color color) : Material() {
    setColor(color);
}

void Lambert::setColor(Color color) {
    this->color = color;
}

Color Lambert::getColor() {
    return color;
}

Color Lambert::computeReflection(Intersection & i, Ray & out) {
    return color / pi;
}

vector<pair<Ray, Color>> Lambert::reflection(Intersection & intersection, int amount) {
    vector<pair<Ray, Color>> result;
    vector<vec2> r = Sampler::jitter2D(amount);
    for (int i = 0; i < r.size(); i++) {
        float u = 2 * pi * r[i].x;
        float v = sqrt(1 - r[i].y);
        vec3 dir = vec3(v * cos(u), sqrt(r[i].y), v * sin(u));
        Ray ray = Ray(intersection.getPosition(), dir, intersection.getRay().getDepth() + 1);
        result.push_back(make_pair(ray, color / pi));
    }
    return result;
}

Color Lambert::emission() {
    return Color::BLACK;
}
