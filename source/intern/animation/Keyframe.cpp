#include "animation/Keyframe.h"

template<typename T>
Keyframe::Keyframe(int frame, T value) {
    setFrame(frame);
    setValue(value);
}

template<typename T>
void Keyframe<T>::setFrame(int frame) {
    this->frame = frame;
}

template<typename T>
void Keyframe<T>::setValue(T value) {
    this->value = value;
}

template<typename T>
int Keyframe<T>::getFrame() {
    return frame;
}

template<typename T>
T & Keyframe<T>::getValue() {
    return value;
}

template<typename T>
bool Keyframe<T>::operator<(Keyframe<T> k) {
    return frame < k.frame;
}

template<typename T>
bool Keyframe<T>::operator==(Keyframe<T> k) {
    return frame == k.frame;
}
