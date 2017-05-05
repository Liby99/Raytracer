#include "engine/PathTracer.h"

PathTracer::PathTracer() : PathTracer(DEFAULT_MAX_DEPTH) {}

PathTracer::PathTracer(int maxDepth) : RenderEngine() {
    setMaxDepth(maxDepth);
}

PathTracer::PathTracer(Scene & scene) : PathTracer(scene, DEFAULT_MAX_DEPTH) {}

PathTracer::PathTracer(Scene & scene, int maxDepth) : RenderEngine(scene) {
    setMaxDepth(maxDepth);
}

int PathTracer::getMaxDepth() {
    return maxDepth;
}

void PathTracer::setMaxDepth(int maxDepth) {
    this->maxDepth = maxDepth;
}

Color PathTracer::getColor(Intersection & intersection) {
    
    Color color = Color::BLACK;
    
    if (intersection.getObject().hasMaterial()) {
        
        Material & mtl = intersection.getObject().getMaterial();
        vec3 normal = intersection.getNormal();
        
        color += mtl.emission();
        
        if (intersection.getRay().getDepth() < maxDepth) {
            vector<pair<Ray, Color>> reflections = mtl.reflection(intersection, 1);
            if (reflections.size() > 0) {
                color += scene->getRayColor(reflections[0].first) * reflections[0].second;
            }
        }
        
        int lightIndex = Sampler::random() * scene->lightAmount();
        Light & light = scene->getLight(lightIndex);
        vector<vec3> dirs = light.getToLightDirection(intersection, 1);
        if (dirs.size() > 0) {
            vec3 dir = dirs[0];
            Ray toLight = Ray(intersection.getPosition(), dir);
            float brightness = light.getBrightness(*scene, intersection, toLight);
            if (brightness > 0.0f) {
                Color lc = light.getColor() * brightness;
                float cosTheta = max(dot(dir, normal), 0.0f);
                Color ob = mtl.computeReflection(intersection, toLight) * cosTheta;
                color += lc * ob;
            }
        }
    }
    
    return color;
}
