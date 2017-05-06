#ifndef ANIMATABLE_H
#define ANIMATABLE_H

#include "animation/Keyframe.h"

#include <map>
<<<<<<< HEAD
=======
#include <functional>
>>>>>>> animation

using namespace std;

template <typename T>
class Animatable {
private:
    
    //
    int startFrame;
    int endFrame;
    T value;
<<<<<<< HEAD
    map<int, Keyframe<T> *> keys;
=======
    map<float, Keyframe<T> *> keys;
>>>>>>> animation
    
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
<<<<<<< HEAD
    bool set(T value);
=======
    void set(T value);
    void set(function<void(T &)> lambda);
    void set(int frame, T value);
    void set(int frame, function<void(T &)> lambda);
>>>>>>> animation
    T get(float frame);
};

#endif
