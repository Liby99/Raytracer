#ifndef ANIMATABLE_H
#define ANIMATABLE_H

#include "animation/Keyframe.h"

#include <map>

using namespace std;

template <typename T>
class Animatable {
private:
    
    //
    int startFrame;
    int endFrame;
    T value;
    map<int, Keyframe<T> *> keys;
    
public:
    
    // Constructor
    Animatable();
    
    //
    bool hasKeyframe();
    unsigned int keyframeAmount();
    Keyframe<T> & getKeyframe(int frame);
    bool addKeyframe(int frame, T value);
    bool removeKeyframe(int frame);
    
    //
    bool set(T value);
    T get(float frame);
};

#endif
