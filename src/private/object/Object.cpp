#include "object/Object.h"

const vec3 Object::DEFAULT_POSITION = vec3(0, 0, 0);
const vec3 Object::DEFAULT_SCALER = vec3(1, 1, 1);
const vec3 Object::DEFAULT_ROTATION = vec3(0, 0, 0);

bool Object::updateIntersect(const Ray & ray, Intersection & intersection) const {
    return false;
}

Object::Object() {
    setRotate(DEFAULT_ROTATION);
    setTranslate(DEFAULT_POSITION);
    setScale(DEFAULT_SCALER);
}

int Object::materialAmount() const {
    return materials.size();
}

Material & Object::getMaterial(int i) const {
    return *(materials[i]);
}

void Object::addMaterial(Material & material) {
    materials.push_back(&material);
}

vec3 Object::getRotation() const {
    return rotation;
}

vec3 Object::getScale() const {
    return scaler;
}

vec3 Object::getPosition() const {
    return position;
}

void Object::setRotate(const vec3 rotation) {
    this->rotation = rotation;
}

void Object::rotate(const vec3 rotation) {
    this->rotation += rotation;
}

void Object::rotateX(const float degX) {
    rotation.x += degX;
}

void Object::rotateY(const float degY) {
    rotation.y += degY;
}

void Object::rotateZ(const float degZ) {
    rotation.z += degZ;
}

void Object::setTranslate(const vec3 translate) {
    this->position = translate;
}

void Object::translate(const vec3 translate) {
    this->position += translate;
}

void Object::translateX(const float x) {
    position.x += x;
}

void Object::translateY(const float y) {
    position.y += y;
}

void Object::translateZ(const float z) {
    position.z += z;
}

void Object::setScale(const vec3 scaler) {
    this->scaler = scaler;
}

void Object::scale(const vec3 scaler) {
    this->scaler *= scaler;
}

void Object::scaleX(const float scaleX) {
    scaler.x *= scaleX;
}

void Object::scaleY(const float scaleY) {
    scaler.y *= scaleY;
}

void Object::scaleZ(const float scaleZ) {
    scaler.z *= scaleZ;
}

mat4 Object::getTransformMatrix() const {
    mat4 scale = Transform::scale(scaler.x, scaler.y, scaler.z);
    mat4 translate = Transform::translate(position.x, position.y, position.z);
    mat4 rotationX = Transform::rotate(rotation.x, vec3(1, 0, 0));
    mat4 rotationY = Transform::rotate(rotation.y, vec3(0, 1, 0));
    mat4 rotationZ = Transform::rotate(rotation.z, vec3(0, 0, 1));
    return translate * rotationZ * rotationY * rotationX * scale;
}

bool Object::intersect(const Ray & ray, Intersection & intersection) const {
    Ray transfRay = ray.inverseTransform(getTransformMatrix());
    if (updateIntersect(transfRay, intersection)) {
        intersection.transform(getTransformMatrix());
        intersection.setObject(*this);
        return true;
    }
    else {
        return false;
    }
}
