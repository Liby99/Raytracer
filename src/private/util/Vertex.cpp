#include "util/Vertex.h"

Vertex::Vertex(vec3 position) {
    setPosition(position);
    setNormal(vec3());
}

Vertex::Vertex(vec3 position, vec3 normal) {
    setPosition(position);
    setNormal(normal);
}

vec3 Vertex::getPosition() {
    return position;
}

void Vertex::setPosition(vec3 position) {
    this->position = position;
}

vec3 Vertex::getNormal() {
    return normal;
}

void Vertex::setNormal(vec3 normal) {
    this->normal = normal;
}

void addUnnormalized(vec3 normal) {
    this->normal += normal;
}

void divideNormal(float num) {
    this->normal /= num;
}

void normalize() {
    this->normal = normalize(this->normal);
}
