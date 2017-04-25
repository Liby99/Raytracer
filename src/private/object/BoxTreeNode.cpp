#include "object/BoxTreeNode.h"

#include <iostream>

using namespace std;

int tricount = 0;

BoxTreeNode::BoxTreeNode(Triangle * tri) {
    box = BoundingBox(tri);
    triangles.push_back(tri);
    left = nullptr;
    right = nullptr;
    leafFlag = true;
}

BoxTreeNode::BoxTreeNode(vector<Triangle *> & tris) : BoxTreeNode(tris, 0, tris.size()) {}

BoxTreeNode::BoxTreeNode(vector<Triangle *> & tris, int start, int amount) {
    
    // Construct Bounding Box
    box = BoundingBox();
    for (int i = start; i < start + amount; i++) {
        box.extend(*tris[i]);
    }
    
    vec3 dimension = box.getSize();
    int axis = maxAxis(dimension);
    float mid = box.getMinCorner()[axis] + dimension[axis] / 2.0f;
    
    // Check the amount
    if (amount == 0) {
        leafFlag = false;
    }
    else if (amount == 1) {
        leafFlag = true;
        triangles.push_back(tris[start]);
    }
    else if (amount == 2) {
        leafFlag = false;
        left = new BoxTreeNode(tris[start]);
        right = new BoxTreeNode(tris[start + 1]);
    }
    else {
        int curr = start;
        for (int i = start; i < start + amount; i++) {
            if (tris[i]->getCenter()[axis] < mid) {
                swap(tris[i], tris[curr]);
                curr++;
            }
        }
        int na = curr - start;
        if (na == 0 || na == amount) {
            for (int i = start; i < start + amount; i++) {
                triangles.push_back(tris[i]);
            }
            leafFlag = true;
        }
        else {
            left = new BoxTreeNode(tris, start, na);
            right = new BoxTreeNode(tris, start + na, amount - na);
            box = BoundingBox::combine(left->getBoundingBox(), right->getBoundingBox());
            leafFlag = false;
        }
    }
}

BoxTreeNode::~BoxTreeNode() {
    if (!isLeaf()) {
        delete left;
        delete right;
    }
}

BoxTreeNode & BoxTreeNode::getLeft() {
    return *left;
}

BoxTreeNode & BoxTreeNode::getRight() {
    return *right;
}

BoundingBox & BoxTreeNode::getBoundingBox() {
    return box;
}

bool BoxTreeNode::leftRightIntersect() {
    if (isLeaf()) {
        return false;
    }
    return left->getBoundingBox().intersect(right->getBoundingBox());
}

bool BoxTreeNode::isLeaf() {
    return leafFlag;
}

bool BoxTreeNode::intersect(Ray & ray, Intersection & intersection) {
    
    bool hit = false;
    
    if (isLeaf()) {
        
        for (int i = 0; i < triangles.size(); i++) {
            if (triangles[i]->intersect(ray, intersection)) {
                hit = true;
            }
        }
        return hit;
    }
    else {
        
        // Prepare all the variables
        BoundingBox & b1 = left->getBoundingBox(), & b2 = right->getBoundingBox();
        float t1 = 0, t2 = 0;
        bool i1 = false, i2 = false;
        i1 = b1.intersect(ray, t1);
        i2 = b2.intersect(ray, t2);
        
        if (t1 < t2) {
            i1 = i1 && (!intersection.hit() || t1 < intersection.getT()) && left->intersect(ray, intersection);
            i2 = i2 && (!intersection.hit() || t2 < intersection.getT()) && right->intersect(ray, intersection);
        }
        else {
            i2 = i2 && (!intersection.hit() || t2 < intersection.getT()) && right->intersect(ray, intersection);
            i1 = i1 && (!intersection.hit() || t1 < intersection.getT()) && left->intersect(ray, intersection);
        }
        
        return i1 || i2;
    }
}
