#ifndef SAMPLER_H
#define SAMPLER_H

#include "util/Random.h"
#include "util/Math.h"
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

class Sampler {
private:
    
    // Helper weighting methods
    static vec2 gaussianWeight(vec2 r);
    static vector<vec2> gaussianWeight(vector<vec2> v);
    
    // Shirley Weighting Methods
    static float shirley(float r);
    static vec2 shirleyWeight(vec2 r);
    static vector<vec2> shirleyWeight(vector<vec2> v);
    
public:
    
    static float random();
    static float random(uint32_t r);
    
    static vector<float> random1D(int amount);
    static vector<float> jitter1D(int amount);
    // vector<float> gaussianJitter1D(int amount);
    // vector<float> shirleyJitter1D(int amount);
    
    static vector<vec2> random2D(int amount);
    static vector<vec2> gaussianRandom2D(int amount);
    static vector<vec2> shirleyRandom2D(int amount);
    static vector<vec2> jitter2D(int side);
    static vector<vec2> gaussianJitter2D(int side);
    static vector<vec2> shirleyJitter2D(int side);
};

#endif
