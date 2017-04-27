#include "object/BoxTreeObject.h"

void BoxTreeObject::forceConstruct() {
    root = new BoxTreeNode(triangles);
}

void BoxTreeObject::constructTree() {
    if (!root) {
        forceConstruct();
    }
}

vector<vec3> BoxTreeObject::getBoundingVertices() {
    constructTree();
    return root->getBoundingBox().getBoundingVertices();
}

bool BoxTreeObject::updateIntersect(Ray & ray, Intersection & intersection) {
    constructTree();
    BoundingBox box = root->getBoundingBox();
    if (box.intersect(ray)) {
        return root->intersect(ray, intersection);
    }
    return false;
}

BoxTreeObject::BoxTreeObject() : MeshObject() {}

BoxTreeObject::BoxTreeObject(const char * filename) : MeshObject(filename) {
    constructTree();
}

BoxTreeObject::~BoxTreeObject() {
    delete root;
}
