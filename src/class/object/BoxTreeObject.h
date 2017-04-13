#ifndef BVH_TREE_H
#define BVH_TREE_H

#include "object/MeshObject.h"
#include "object/Triangle.h"

class BoxTriangle : public Triangle {
    
}

class Box {
private:
    vec3 minCorner;
    vec3 maxCorner;
    bool hasObj;
    
    void extend(const BvhTriangle & tri);
public:
    
    bool intersect(const Ray & ray);
    bool intersect(const Box & box);
}

class BoxTreeNode {
    
}

class BoxTreeObject : public MeshObject {
protected:
    
    construct();
public:
    
};

#endif
