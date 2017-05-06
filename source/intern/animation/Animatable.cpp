#include "animation/Animatable.h"

template<typename T>
Animatable<T>::Animatable() {}

template<typename T>
bool Animatable<T>::hasKeyframe() {
    return keys.size() > 0;
}

template<typename T>
Keyframe<T> & Animatable<T>::getKeyframe(int frame) {
    auto it = keys.find(frame);
    if (it == keys.end()) {
        throw invalid_argument("Keyframe does not exist");
    }
    return *(it->second);
}

template<typename T>
bool Animatable<T>::addKeyframe(int frame, T value) {
    auto it = keys.find(frame);
    if (it != keys.end()) {
        return false;
    }
    it->second = new Keyframe<T>(frame, value);
    return true;
}

template<typename T>
bool Animatable<T>::removeKeyframe(int frame) {
    auto it = keys.find(frame);
    if (it == keys.end()) {
        return false;
    }
    delete it->second;
    keys.erase(it);
    return true;
}

template<typename T>
bool Animatable<T>::set(T value) {
    this->value = value;
}

template<typename T>
T Animatable<T>::get(float t) {
    if (keys.empty()) {
        return value;
    }
    else {
        auto lit = keys.lower_bound(t);
        if (lit == keys.begin()) {
            return value;
        }
        else {
            auto git = lit;
            lit--;
            if (git == keys.end()) {
                return lit->second->getValue();
            }
            else {
                int s = lit->second->getFrame();
                int e = git->second->getFrame();
                float o = t - s;
                float progress = o / (e - s);
                T lval = lit->second->getValue();
                T rval = git->second->getValue();
                return lval + progress * (rval - lval);
            }
        }
    }
}
