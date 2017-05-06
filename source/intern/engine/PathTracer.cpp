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

Color PathTracer::getColor(Intersection & intersection, float t) {
    
    Color color = Color::BLACK;
    if (intersection.getObject().hasMaterial()) {
        
        // Cache the material and normal
        Material & mtl = intersection.getObject().getMaterial();
        vec3 normal = intersection.getNormal();
        
        // Calculate the Emission
        color += mtl.emission();
        
        // Calculate the Reflection
        if (intersection.getRay().getDepth() < maxDepth) {
            vector<pair<Ray, Color>> reflections = mtl.reflection(intersection, 1);
            if (reflections.size() > 0) {
                color += scene->getRayColor(reflections[0].first, t) * reflections[0].second;
            }
        }
        
        // Calculate the Reflection to Light
        if (scene->hasLight()) {
            
            // First random a light from all the lights in the scene
            int lightIndex = rand() % scene->lightAmount();
            Light & light = scene->getLight(lightIndex);
            
            // Get the direction of it and generate a ray towards it
            vec3 dir = light.getToLightDirection(intersection);
            Ray toLight = Ray(intersection.getPosition(), dir);
            
            // Calculate the brightness of the intersection by the light
            float brightness = light.getBrightness(*scene, intersection, toLight, t);
            if (brightness > 0.0f) {
                
                // Then calculate the reflection color to that light
                Color lc = light.getColor() * brightness;
                float cosTheta = max(dot(dir, normal), 0.0f);
                Color ob = mtl.computeReflection(intersection, toLight) * cosTheta;
                color += lc * ob;
            }
        }
    }
    return color;
}
