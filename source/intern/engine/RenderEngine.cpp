#include "engine/RenderEngine.h"

RenderEngine::RenderEngine() {};

RenderEngine::RenderEngine(Scene & scene) {
    setScene(scene);
}

void RenderEngine::setScene(Scene & scene) {
    this->scene = &scene;
}

Scene & RenderEngine::getScene() {
    return *scene;
}

Color RenderEngine::getColor(Intersection & intersection) {
    return Color();
}
