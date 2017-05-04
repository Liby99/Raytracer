#include "material/Lambert.h"

Lambert::Lambert() : Lambert(Color::WHITE) {}

Lambert::Lambert(Color color) {
    setColor(color);
}

void Lambert::setColor(Color color) {
    this->color = color;
}

Color Lambert::getColor() {
    return color;
}

vector<pair<Ray, Color>> Lambert::reflection(Intersection & intersection, int amount) {
    vector<pair<Ray, Color>> result;
    for (int i = 0; i < amount; i++) {
        vec2 r = Sampler::random2D();
        float u = 2 * pi * r.x;
        float v = sqrt(1 - r.y);
        vec3 dir = vec3(v * cos(u), sqrt(r.y), v * sin(u));
        result.push_back(make_pair(Ray(intersection.getPosition(), dir), color / pi));
    }
    return result;
}

Color Lambert::emission() {
    return Color();
}
