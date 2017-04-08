#include "camera/Camera.h"

Camera::DEFAULT_POSITION = vec3(0, 0, 1);
Camera::DEFAULT_FOCAL_POINT = vec3(0, 0, 0);
Camera::DEFAULT_UP = vec3(0, 1, 0);
Camera::DEFAULT_WIDTH = 720;
Camera::DEFAULT_HEIGHT = 540;
Camera::DEFAULT_FOVY = 90;

Camera::Camera() {
    lookAt(DEFAULT_POSITION, DEFAULT_FOCAL_POINT, DEFAULT_UP);
    setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
}

Camera::Camera(vec3 position, vec3 focalPoint, vec3 up) {
    lookAt(position, focalPoint, up);
    setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
}

void Camera::lookAt(vec3 position, vec3 focalPoint, vec3 up) {
    setPosition(position);
    setFocalPoint(focalPoint);
    setUp(up);
}

void setPosition(vec3 position) {
    this->position = position;
}

void setFocalPoint(vec3 focalPoint) {
    this->focalPoint = focalPoint;
}

void setUp(vec3 up) {
    this->up = up;
}

vec3 getPosition() {
    return position;
}

vec3 getFocalPoint() {
    return focalPoint;
}

vec3 getUp() {
    return up;
}

void setSize(int width, int height) {
    setWidth(width);
    setHeight(height);
}

void setWidth(int width) {
    this->width = width;
}

void setHeight(int height) {
    this->height = height;
}

void setFovy(float fovy) {
    this->fovy = fovy;
}

Bitmap render(const Scene & scene) {
    
    Bitmap bitmap(width, height);
    
    // Setup ray origin
    Ray ray;
    ray.setOrigin(position);
    
    // Setup camera variables
    vec3 w = normalize(pos - center);
    vec3 u = normalize(cross(w, up));
    vec3 v = cross(w, u);
    
    // Cached uniform variables
    float betaMult = -tan(glm::radians(fovy / 2));
    float alphaMult = betaMult * width / height;
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    
    // Iterate through all the rays
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            
            // First get the ni and nj
            float ni = i + 0.5;
            float nj = j + 0.5;
            
            // Then calculate alpha and beta then direction of ray
            float alpha = alphaMult * (ni - halfWidth) / halfWidth;
            float beta = betaMult * (nj - halfHeight) / halfHeight;
            vec3 dir = normalize(alpha * u + beta * v - w);
            
            // Set the ray direction
            ray.setDirection(dir);
            
            // Set the related pixel color
            bitmap.setPixel(i, j, scene.getRayColor(ray).toInt());
        }
    }
    
    // Return the bitmap
    return bitmap;
}
