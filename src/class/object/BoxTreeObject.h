#ifndef BOX_TREE_OBJECT_H
#define BOX_TREE_OBJECT_H

#include "object/MeshObject.h"
#include "object/BoxTreeNode.h"

class BoxTreeObject : public MeshObject {
protected:
    
    BoxTreeNode * root;
    
    // Helper construct method
    void forceConstruct();
    void constructTree();
    
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    virtual vector<vec3> getBoundingVertices();
    
public:
    
    //
    BoxTreeObject();
    BoxTreeObject(const char * filename);
    ~BoxTreeObject();
};

#endif
