#include "object/Object.h"

const vec3 Object::DEFAULT_POSITION = vec3(0, 0, 0);
const vec3 Object::DEFAULT_SCALER = vec3(1, 1, 1);
const vec3 Object::DEFAULT_ROTATION = vec3(0, 0, 0);

bool Object::updateIntersect(Ray & ray, Intersection & intersection) {
    return false;
}

Object::Object() {
    setRotate(DEFAULT_ROTATION);
    setTranslate(DEFAULT_POSITION);
    setScale(DEFAULT_SCALER);
}

int Object::materialAmount() {
    return materials.size();
}

Material & Object::getMaterial(int i) {
    return *(materials[i]);
}

void Object::addMaterial(Material & material) {
    materials.push_back(&material);
}

void Object::setRotate(vec3 rotation) {
    this->rotation = rotation;
}

void Object::rotate(vec3 rotation) {
    this->rotation += rotation;
}

void Object::rotateX(float degX) {
    rotation.x += degX;
}

void Object::rotateY(float degY) {
    rotation.y += degY;
}

void Object::rotateZ(float degZ) {
    rotation.z += degZ;
}

void Object::setTranslate(vec3 translate) {
    this->position = translate;
}

void Object::translate(vec3 translate) {
    this->position += translate;
}

void Object::translateX(float x) {
    position.x += x;
}

void Object::translateY(float y) {
    position.y += y;
}

void Object::translateZ(float z) {
    position.z += z;
}

void Object::setScale(vec3 scaler) {
    this->scaler = scaler;
}

void Object::scale(vec3 scaler) {
    this->scaler *= scaler;
}

void Object::scaleX(float scaleX) {
    scaler.x *= scaleX;
}

void Object::scaleY(float scaleY) {
    scaler.y *= scaleY;
}

void Object::scaleZ(float scaleZ) {
    scaler.z *= scaleZ;
}

mat4 Object::getTransformMatrix() {
    mat4 scale = Transform::scale(scaler.x, scaler.y, scaler.z);
    mat4 translate = Transform::translate(position.x, position.y, position.z);
    mat4 rotationX = Transform::rotate(rotation.x, vec3(1, 0, 0));
    mat4 rotationY = Transform::rotate(rotation.y, vec3(0, 1, 0));
    mat4 rotationZ = Transform::rotate(rotation.z, vec3(0, 0, 1));
    return translate * rotationZ * rotationY * rotationX * scale;
}

bool Object::intersect(Ray & ray, Intersection & intersection) {
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
