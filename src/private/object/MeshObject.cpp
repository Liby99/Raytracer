#include "object/MeshObject.h"

bool MeshObject::updateIntersect(const Ray & ray, Intersection & intersection) const {
    bool hit = false;
    for (int i = 0; i < triangles.size(); i++) {
        if (triangles[i]->intersect(ray, intersection)) {
            hit = true;
        }
    }
    return hit;
}

MeshObject::MeshObject() : Object() {
    
}

MeshObject::~MeshObject() {
    clear();
}

void MeshObject::addVertex(const vec3 position) {
    vertices.push_back(new Vertex(position));
}

void MeshObject::addVertex(const vec3 position, const vec3 normal) {
    vertices.push_back(new Vertex(position, normal));
}

void MeshObject::addTriangle(const int i1, const int i2, const int i3) {
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
    vertices = vector<Vertex *>();
}

void MeshObject::clearTriangles() {
    for (int i = 0; i < triangles.size(); i++) {
        delete triangles[i];
    }
    triangles = vector<Triangle *>();
}
