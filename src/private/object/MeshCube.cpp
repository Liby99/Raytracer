#include "object/MeshCube.h"

void MeshCube::clear() {
    mesh.clear();
}

void MeshCube::construct() {
    
    // First calculate half
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float halfLength = length / 2;
    
    // Then add vertices
    mesh.addVertex(vec3(halfWidth, halfHeight, halfLength));
    mesh.addVertex(vec3(halfWidth, halfHeight, -halfLength));
    mesh.addVertex(vec3(halfWidth, -halfHeight, halfLength));
    mesh.addVertex(vec3(halfWidth, -halfHeight, -halfLength));
    mesh.addVertex(vec3(-halfWidth, halfHeight, halfLength));
    mesh.addVertex(vec3(-halfWidth, halfHeight, -halfLength));
    mesh.addVertex(vec3(-halfWidth, -halfHeight, halfLength));
    mesh.addVertex(vec3(-halfWidth, -halfHeight, -halfLength));
    
    // Then add triangles
    mesh.addTriangle(0, 2, 1);
    mesh.addTriangle(1, 2, 3);
    mesh.addTriangle(4, 5, 7);
    mesh.addTriangle(4, 7, 6);
    mesh.addTriangle(1, 5, 4);
    mesh.addTriangle(0, 1, 4);
    mesh.addTriangle(2, 6, 7);
    mesh.addTriangle(2, 7, 3);
    mesh.addTriangle(0, 4, 2);
    mesh.addTriangle(2, 4, 6);
    mesh.addTriangle(1, 7, 5);
    mesh.addTriangle(1, 3, 7);
}

void MeshCube::reconstruct() {
    clearCube();
    constructCube();
}

bool MeshCube::updateIntersect(Ray & ray, Intersection & intersection) {
    if (mesh.intersect(transfRay, intersection)) {
        intersection.setObject(*this);
        return true;
    }
    return false;
}

MeshCube::MeshCube(float width, float height, float length) : Object() {
    setWidth(width);
    setHeight(height);
    setLength(length);
    constructCube();
}

float MeshCube::getWidth() {
    return width;
}

void MeshCube::setWidth(float width) {
    this->width = width;
    reconstruct();
}

float MeshCube::getHeight() {
    return height;
}

void MeshCube::setHeight(float height) {
    this->height = height;
    reconstruct();
}

float MeshCube::getLength() {
    return length;
}

void MeshCube::setLength(float length) {
    this->length = length;
    reconstruct();
}
