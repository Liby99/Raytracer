#include "camera/AntiAliasingCamera.h"

const int AntiAliasingCamera::DEFAULT_LEVEL = 2;

AntiAliasingCamera::AntiAliasingCamera() : Camera() {
    setLevel(DEFAULT_LEVEL);
}

AntiAliasingCamera::AntiAliasingCamera(int level) : Camera() {
    setLevel(level);
}

AntiAliasingCamera::AntiAliasingCamera(vec3 position, vec3 focalPoint, int level) : Camera(position, focalPoint) {
    setLevel(level);
}

AntiAliasingCamera::AntiAliasingCamera(vec3 position, vec3 focalPoint, vec3 up, int level) : Camera(position, focalPoint, up) {
    setLevel(level);
}

int AntiAliasingCamera::getLevel() {
    return level;
}

void AntiAliasingCamera::setLevel(int level) {
    this->level = level;
}

Bitmap AntiAliasingCamera::render(Scene & scene) {
    
    Bitmap bitmap(width, height);
    
    // Setup camera variables
    vec3 w = normalize(focalPoint - position);
    vec3 u = normalize(cross(w, up));
    vec3 v = cross(w, u);
    
    // Cached uniform variables
    float betaMult = -tan(glm::radians(fovy / 2));
    float alphaMult = betaMult * width / height;
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    alphaMult /= halfWidth;
    betaMult /= halfHeight;
    
    // Iterate through all the rays
    #pragma parallel omp for collapse(2)
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            
            Color color;
            
            #pragma parallel omp for collapse(2)
            for (int ax = 0; ax < level; ax++) {
                for (int ay = 0; ay < level; ay++) {
                    
                    // Then calculate alpha and beta then direction of ray
                    float alpha = alphaMult * (halfWidth - i + (float) ax / level + 1.0f / (level * 2));
                    float beta = betaMult * (j - halfHeight + (float) ay / level + 1.0f / (level * 2));
                    vec3 dir = normalize(alpha * u + beta * v + w);
                    
                    Ray ray = Ray(position, dir);
                    color += scene.getRayColor(ray);
                }
            }
            
            color *= 1.0f / (level * level);
            
            // Set the related pixel color
            bitmap.setPixel(i, j, color);
        }
    }
    
    // Return the bitmap
    return bitmap;
}
