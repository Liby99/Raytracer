#ifndef BVH_TREE_H
#define BVH_TREE_H

#include "object/MeshObject.h"
#include "object/Triangle.h"

class BvhTriangle : public Triangle {
    
}

class BvhBox {
private:
    vec3 minCorner;
    vec3 maxCorner;
    bool hasObj;
    
    void extend(const BvhTriangle & tri);
public:
    
}

class BvhNode {
    
}

class BvhTree : public MeshObject {
    
};

#endif
