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
    BoundingBox box;
    
    // Flag of leaf
    bool leafFlag;
    
public:
    
    // Constructor
    BoxTreeNode(vector<Triangle *> tris);
    BoxTreeNode(Triangle * tris);
    ~BoxTreeNode();
    
    BoxTreeNode & getLeft();
    BoxTreeNode & getRight();
    BoundingBox & getBoundingBox();
    bool leftRightIntersect();
    bool isLeaf();
    bool intersect(Ray & ray, Intersection & intersection);
};

class BoxTreeObject : public MeshObject {
protected:
    
    BoxTreeNode * root;
    
    // Helper construct method
    void clearTree();
    void forceConstruct();
    void constructTree();
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    //
    BoxTreeObject();
    BoxTreeObject(char * filename);
    ~BoxTreeObject();
};

#endif
