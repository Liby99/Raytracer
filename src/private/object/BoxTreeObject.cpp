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
        if (root->intersect(ray, intersection)) {
            intersection.setObject(*this);
            return true;
        }
    }
    return false;
}

BoxTreeObject::BoxTreeObject() : MeshObject() {}

BoxTreeObject::BoxTreeObject(char * filename) : MeshObject(filename) {}

BoxTreeObject::~BoxTreeObject() {
    delete root;
}
