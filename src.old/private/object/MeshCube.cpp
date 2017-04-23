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
    clear();
    construct();
}

bool MeshCube::updateIntersect(const Ray & ray, Intersection & intersection) const {
    return mesh.intersect(ray, intersection);
}

vector<vec3> MeshCube::getBoundingVertices() {
    return Cube::getBoundingVertices();
}

MeshCube::MeshCube() : Cube() {
    construct();
}

MeshCube::MeshCube(const float width, const float height, const float length) : Cube(width, height, length) {
    construct();
}

void MeshCube::setWidth(const float width) {
    Cube::setWidth(width);
    reconstruct();
}

void MeshCube::setHeight(const float height) {
    Cube::setHeight(height);
    reconstruct();
}

void MeshCube::setLength(const float length) {
    Cube::setLength(length);
    reconstruct();
}
