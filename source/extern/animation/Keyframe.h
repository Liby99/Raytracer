#ifndef KEYFRAME_H
#define KEYFRAME_H

template <typename T>
class Keyframe {
private:
    int frame;
    T value;
public:
    Keyframe(int frame, T value);
    bool operator<(Keyframe k);
};

#endif
