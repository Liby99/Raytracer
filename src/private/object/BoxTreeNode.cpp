#include "object/BoxTreeNode.h"

#include <iostream>

using namespace std;

BoxTreeNode::BoxTreeNode(Triangle * tri) {
    box = BoundingBox(tri);
    triangles.push_back(tri);
    left = nullptr;
    right = nullptr;
    leafFlag = true;
}

BoxTreeNode::BoxTreeNode(vector<Triangle *> & tris) {
    int n = tris.size();
    
    // Construct Bounding Box
    box = BoundingBox();
    for (int i = 0; i < n; i++) {
        box.extend(*tris[i]);
    }
    
    vec3 dimension = box.getSize();
    int axis = maxAxis(dimension);
    float mid = box.getMinCorner()[axis] + dimension[axis] / 2.0f;
    
    //
    if (n == 0) {
        leafFlag = false;
    }
    else if (n == 1) {
        leafFlag = true;
        triangles.push_back(tris[0]);
    }
    else if (n == 2) {
        left = new BoxTreeNode(tris[0]);
        right = new BoxTreeNode(tris[1]);
    }
    else {
        vector<Triangle *> leftTris;
        vector<Triangle *> rightTris;
        for (int i = 0; i < n; i++) {
            if (tris[i]->getCenter()[axis] < mid) {
                leftTris.push_back(tris[i]);
            }
            else {
                rightTris.push_back(tris[i]);
            }
        }
        if (leftTris.size() == tris.size() || rightTris.size() == tris.size()) {
            triangles = tris;
            leafFlag = true;
        }
        else {
            left = new BoxTreeNode(leftTris);
            right = new BoxTreeNode(rightTris);
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
        
        // Check intersection
        if (i1 && left->intersect(ray, intersection)) {
            hit = true;
        }
        if (i2 && right->intersect(ray, intersection)) {
            hit = true;
        }
        
        return hit;
    }
}
