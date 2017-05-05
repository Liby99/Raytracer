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
    return color;
}

vector<pair<Ray, Color>> Lambert::reflection(Intersection & intersection, int amount) {
    vector<pair<Ray, Color>> result;
    vector<vec2> r = Sampler::jitter2D(amount);
    for (int i = 0; i < r.size(); i++) {
        float u = 2 * pi * r[i].x;
        float v = sqrt(1 - r[i].y);
        vec3 norm = intersection.getNormal();
        vec3 udir = normalize(cross(norm, norm + vec3(0.2f, 0.7f, 0.1f)));
        vec3 vdir = normalize(cross(norm, udir));
        vec3 dir = udir * v * cos(u) + norm * sqrt(r[i].y) + vdir * v * sin(u);
        Ray ray = Ray(intersection.getPosition(), dir, intersection.getRay().getDepth() + 1);
        ray.increment();
        result.push_back(make_pair(ray, color));
    }
    return result;
}

Color Lambert::emission() {
    return Color::BLACK;
}
