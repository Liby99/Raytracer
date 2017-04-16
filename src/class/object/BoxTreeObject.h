#ifndef BVH_TREE_H
#define BVH_TREE_H

#include "object/MeshObject.h"
#include "object/Triangle.h"

class BoxTreeNode {
private:
    
    // Left and right nodes if not leaf
    BoxTreeNode * left;
    BoxTreeNode * right;
    
    // Triangles that stores inside the node
    vector<Triangle *> triangles;
    
    // Box object
    Box box;
    
    // Flag of leaf
    bool leafFlag;
    
public:
    
    // Constructor
    BoxTreeNode(vector<Triangle *> objs);
    
    BoxTreeNode & getLeft() const;
    BoxTreeNode & getRight() const;
    bool leftRightIntersect() const;
    bool isLeaf();
};

class BoxTreeObject : public MeshObject {
protected:
    
    BoxTreeNode * root;
    
    // Helper construct method
    void construct();
    
public:
    
    BoxTreeObject();
};

#endif
