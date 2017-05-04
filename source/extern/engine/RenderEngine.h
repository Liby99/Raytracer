#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include "scene/Scene.h"

class RenderEngine {
private:
    Scene * scene;
public:
    RenderEngine();
    RenderEngine(Scene & scene);
    void setScene(Scene & scene);
    Scene & getScene();
    virtual Color getColor(Intersection & intersection);
};

#endif
