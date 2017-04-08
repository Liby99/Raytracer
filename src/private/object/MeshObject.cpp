#include "object/MeshObject.h"

bool MeshObject::updateIntersect(Ray & ray, Intersection & intersection) {
    bool hit = false;
    for (int i = 0; i < triangles.size(); i++) {
        if (triangles[i]->intersect(transfRay, intersection)) {
            hit = true;
        }
    }
    if (hit) {
        intersection.setObject(*this);
        return true;
    }
    return false;
}

MeshObject::MeshObject() : Object() {
    
}

MeshObject::~MeshObject() {
    clear();
}

void MeshObject::addVertex(vec3 position) {
    vertices.push_back(new Vertex(position));
}

void MeshObject::addVertex(vec3 position, vec3 normal) {
    vertices.push_back(new Vertex(position, normal));
}

void MeshObject::addTriangle(int i1, int i2, int i3) {
    triangles.push_back(new Triangle(vertices[i1], vertices[i2], vertices[i3]));
}

void MeshObject::clear() {
    clearVertices();
    clearTriangles();
}

void MeshObject::clearVertices() {
    for (int i = 0; i < vertices.size(); i++) {
        delete vertices[i];
    }
}

void MeshObject::clearTriangles() {
    for (int i = 0; i < triangles.size(); i++) {
        delete triangles[i];
    }
}
