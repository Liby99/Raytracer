#ifndef BOX_TREE_NODE_H
#define BOX_TREE_NODE_H

#include "object/Triangle.h"

class BoxTreeNode {
private:
    
    // Left and right nodes if not leaf
    BoxTreeNode * left;
    BoxTreeNode * right;
    
    // Triangles that stores inside the node
    vector<Triangle *> triangles;
    
    // Box object
    BoundingBox box;
    
    // Flag of leaf
    bool leafFlag;
    
public:
    
    // Constructor
    BoxTreeNode(Triangle * tris);
    BoxTreeNode(vector<Triangle *> & tris);
    ~BoxTreeNode();
    
    BoxTreeNode & getLeft();
    BoxTreeNode & getRight();
    BoundingBox & getBoundingBox();
    bool leftRightIntersect();
    bool isLeaf();
    bool intersect(Ray & ray, Intersection & intersection);
};

#endif
