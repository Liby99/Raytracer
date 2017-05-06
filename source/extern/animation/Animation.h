#ifndef ANIMATABLE_H
#define ANIMATABLE_H

template <typename T> class Animatable {
private:
    int startFrame;
    int endFrame;
    T value;
    vector<Keyframe<T>> keys;
public:
    bool setValue(int frame, T value);
    T getValue(float frame);
};

#endif
