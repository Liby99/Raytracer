#include "object/MeshCube.h"

MeshCube::MeshCube(float width, float height, float length) : Object() {
    
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

bool MeshCube::intersect(Ray & ray, Intersection & intersection) {
    Ray transfRay = ray.inverseTransform(getTransformMatrix());
    bool result = mesh.intersect(transfRay, intersection);
    intersection.transform(getTransformMatrix());
    intersection.setObject(*this);
    return result;
}
