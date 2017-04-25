#include "object/BoxTreeObject.h"
#include "module/StopWatch.h"
#include <iostream>

void BoxTreeObject::forceConstruct() {
    root = new BoxTreeNode(triangles);
}

void BoxTreeObject::constructTree() {
    if (!root) {
        StopWatch watch;
        watch.start();
        forceConstruct();
        cout << "Completed building tree in " << watch.stop() << "s." << endl;
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
