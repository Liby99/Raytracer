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

vector<vec3> MeshObject::getBoundingVertices() {
    vec3 minCorner;
    vec3 maxCorner;
    for (int i = 0; i < vertices.size(); i++) {
        minCorner = minVec(minCorner, vertices[i].getPosition());
        maxCorner = maxVec(maxCorner, vertices[i].getPosition());
    }
    vector<vec3> result;
    result.push_back(vec3(maxCorner.x, maxCorner.y, maxCorner.z));
    result.push_back(vec3(maxCorner.x, maxCorner.y, minCorner.z));
    result.push_back(vec3(maxCorner.x, minCorner.y, maxCorner.z));
    result.push_back(vec3(maxCorner.x, minCorner.y, minCorner.z));
    result.push_back(vec3(minCorner.x, maxCorner.y, maxCorner.z));
    result.push_back(vec3(minCorner.x, maxCorner.y, minCorner.z));
    result.push_back(vec3(minCorner.x, minCorner.y, maxCorner.z));
    result.push_back(vec3(minCorner.x, minCorner.y, minCorner.z));
    return result;
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

bool loadPly(const char * filename) {
    
}

void smooth() {
    int i, j;
    for (i = 0; i < vertices.size(); i++) {
        vertices[i].setNormal(vec3(0));
    }
    for (i = 0; i < triangles.size(); i++) {
        Triangle & tri = *triangles[i];
        vec3 e1 = tri.getV2().getPosition() - tri.getV1().getPosition();
        vec3 e1 = tri.getV3().getPosition() - tri.getV1().getPosition();
        vec3 c = cross(e1, e2);
        for (j = 0; j < 3; j++) {
            tri.GetVtx(j).Normal += cross;
        }
    }
}
