#include "util/Vertex.h"

Vertex::Vertex(vec3 position) {
    setPosition(position);
    setNormal(vec3());
}

Vertex::Vertex(vec3 position, vec3 normal) {
    setPosition(position);
    setNormal(normal);
}

vec3 Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(vec3 position) {
    this->position = position;
}

vec3 Vertex::getNormal() const {
    return normal;
}

void Vertex::setNormal(vec3 normal) {
    this->normal = normal;
}
