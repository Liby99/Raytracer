#ifndef BVH_SCENE_H
#define BVH_SCENE_H

#include "scene/Scene.h"
#include "bvh/BvhTree.h"
#include "bvh/BvhNode.h"
#include "bvh/BvhBox.h"

class BvhScene : public Scene {
protected:
    BvhTree bvhTree;
    void constructBvh();
public:
    BvhScene();
    ~BvhScene();
    virtual bool getIntersection(Ray & ray, Intersection & intersection);
    virtual Color getIntersectionColor(Intersection & intersection);
    virtual Color getRayColor(Ray & ray);
};

#endif
