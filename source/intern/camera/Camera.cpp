#include "camera/Camera.h"

const vec3 Camera::DEFAULT_POSITION = vec3(0, 0, 1);
const vec3 Camera::DEFAULT_FOCAL_POINT = vec3(0, 0, 0);
const vec3 Camera::DEFAULT_UP = vec3(0, 1, 0);
const int Camera::DEFAULT_WIDTH = 720;
const int Camera::DEFAULT_HEIGHT = 480;
const float Camera::DEFAULT_FOVY = 90;

vector<vec2> Camera::getSample() {
    return Sampler::sample2D(samplingAmount, samplingMethod, weightingMethod);
}

Camera::Camera() : Camera(DEFAULT_POSITION, DEFAULT_FOCAL_POINT) {}

Camera::Camera(vec3 position, vec3 focalPoint) : Camera(position, focalPoint, DEFAULT_UP) {}

Camera::Camera(vec3 position, vec3 focalPoint, vec3 up) {
    
    // Set up basic parameters
    lookAt(position, focalPoint, up);
    setResolution(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
    
    // Setup sampling parameters
    disableSampling();
    setSamplingMethod(Sampler::UNIFORM_SAMPLE);
    setWeightingMethod(Sampler::NO_WEIGHT);
    setSamplingAmount(1);
}

void Camera::lookAt(vec3 position, vec3 focalPoint) {
    setPosition(position);
    setFocalPoint(focalPoint);
    setUp(DEFAULT_UP);
}

void Camera::lookAt(vec3 position, vec3 focalPoint, vec3 up) {
    setPosition(position);
    setFocalPoint(focalPoint);
    setUp(up);
}

void Camera::setPosition(vec3 position) {
    this->position = position;
}

void Camera::setFocalPoint(vec3 focalPoint) {
    this->focalPoint = focalPoint;
}

void Camera::setUp(vec3 up) {
    this->up = up;
}

vec3 Camera::getPosition() {
    return position;
}

vec3 Camera::getFocalPoint() {
    return focalPoint;
}

vec3 Camera::getUp() {
    return up;
}

void Camera::setResolution(int width, int height) {
    setWidth(width);
    setHeight(height);
}

void Camera::setWidth(int width) {
    this->width = width;
}

void Camera::setHeight(int height) {
    this->height = height;
}

void Camera::setFovy(float fovy) {
    this->fovy = fovy;
}

bool Camera::isSampling() {
    return sampling;
}

void Camera::enableSampling() {
    sampling = true;
}

void Camera::disableSampling() {
    sampling = false;
}

int Camera::getSamplingMethod() {
    return samplingMethod;
}

int Camera::getWeightingMethod() {
    return weightingMethod;
}

void Camera::setSamplingMethod(int method) {
    this->samplingMethod = method;
}

void Camera::setWeightingMethod(int method) {
    this->weightingMethod = method;
}

int Camera::getSamplingAmount() {
    return samplingAmount;
}

void Camera::setSamplingAmount(int amount) {
    this->samplingAmount = amount;
}

void Camera::onRender(function<void(int, int, Color, float)> func) {
    hasOnRenderCallback = true;
    onRenderCallback = func;
}

Image Camera::render(Scene & scene) {
    
    // Setup image buffer
    Image image(width, height);
    
    // Setup camera variables
    vec3 w = normalize(focalPoint - position);
    vec3 u = normalize(cross(w, up));
    vec3 v = cross(w, u);
    
    // Cached uniform variables
    float betaMult = -tan(glm::radians(fovy / 2));
    float alphaMult = betaMult * width / height;
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float a = alphaMult / halfWidth;
    float b = betaMult / halfHeight;
    
    unsigned int total = width * height;
    unsigned int step = 0;
    
    // Iterate through all the rays
    #pragma omp parallel for collapse(2)
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            
            Color color;
            
            if (sampling) {
                
                vector<vec2> samples = getSample();
                Color base = Color();
                
                #pragma omp parallel for
                for (int k = 0; k < samples.size(); k++) {
                    float alpha = a * (halfWidth - i + samples[k].x);
                    float beta = b * (j - halfHeight + samples[k].y);
                    vec3 dir = normalize(alpha * u + beta * v + w);
                    Ray ray = Ray(position, dir);
                    base += scene.getRayColor(ray);
                }
                base /= samples.size();
                color = base;
            }
            else {
                
                // Generate the only ray
                float alpha = a * (halfWidth - i + 0.5f);
                float beta = b * (j - halfHeight + 0.5f);
                vec3 dir = normalize(alpha * u + beta * v + w);
                Ray ray = Ray(position, dir);
                color = scene.getRayColor(ray);
            }
            
            image.setPixel(i, j, color);
            
            #pragma omp atomic
            step++;
            
            if (hasOnRenderCallback) {
                #pragma omp critical
                onRenderCallback(i, j, color, (float) step / total);
            }
        }
    }
    
    // Return the image
    return image;
}
