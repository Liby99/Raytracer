#ifndef ANIMATABLE_H
#define ANIMATABLE_H

#include "animation/Keyframe.h"

#include <map>
#include <functional>

using namespace std;

template <typename T>
class Animatable {
private:
    
    //
    int startFrame;
    int endFrame;
    T value;
    map<float, Keyframe<T> *> keys;
    
public:
    
    // Constructor
    Animatable();
    
    // Keyframe getter and setter
    bool hasKeyframe();
    unsigned int keyframeAmount();
    Keyframe<T> & getKeyframe(int frame);
    bool addKeyframe(int frame, T value);
    bool removeKeyframe(int frame);
    
    // Value setter, modifier and getter
    void set(T value);
    void set(function<void(T &)> lambda);
    void set(int frame, T value);
    void set(int frame, function<void(T &)> lambda);
    T get(float frame);
};

#endif
