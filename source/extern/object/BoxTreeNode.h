#ifndef BOX_TREE_NODE_H
#define BOX_TREE_NODE_H

#include "object/Triangle.h"

class BoxTreeNode {
protected:
    
    // Left and right nodes if not leaf
    BoxTreeNode * left;
    BoxTreeNode * right;
    
    // Variables
    vector<Triangle *> triangles;
    BoundingBox box;
    bool leafFlag;
    
    // Protected constructor, only used for internal call
    BoxTreeNode(vector<Triangle *> & tris, int start, int amount);
    
public:
    
    // Constructor
    BoxTreeNode(Triangle * tris);
    BoxTreeNode(vector<Triangle *> & tris);
    ~BoxTreeNode();
    
    // Getter
    BoxTreeNode & getLeft();
    BoxTreeNode & getRight();
    BoundingBox & getBoundingBox();
    
    // Helper Methods
    bool leftRightIntersect();
    bool isLeaf();
    bool intersect(Ray & ray, Intersection & intersection);
};

#endif
