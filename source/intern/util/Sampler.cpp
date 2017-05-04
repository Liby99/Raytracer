#include "util/Sampler.h"

vec2 Sampler::gaussianWeight(vec2 r) {
    float a = 0.4f * sqrt(-2.0f * log(r.x));
    float b = 2.0f * pi * r.y;
    return vec2(0.5 + a * sin(b), 0.5 + a * cos(b));
}

vector<vec2> Sampler::gaussianWeight(vector<vec2> v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = gaussianWeight(v[i]);
    }
    return v;
}

float Sampler::shirley(float r) {
    if (r < 0.5) {
        return -0.5 + sqrt(2 * r);
    }
    else {
        return 1.5 - sqrt(2 - 2 * r);
    }
}

vec2 Sampler::shirleyWeight(vec2 r) {
    return vec2(shirley(r.x), shirley(r.y));
}

vector<vec2> Sampler::shirleyWeight(vector<vec2> v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = shirleyWeight(v[i]);
    }
    return v;
}

float Sampler::random() {
    uint64_t r = Random::next();
    return random(r);
}

float Sampler::random(uint32_t r) {
    return (float) r / INT_MAX;
}

vector<float> Sampler::random1D(int amount) {
    vector<float> result;
    for (int i = 0; i < amount; i++) {
        result.push_back(Sampler::random());
    }
    return result;
}

vector<float> Sampler::jitter1D(int amount) {
    vector<float> result;
    float interval = 1.0f / amount;
    for (int i = 0; i < amount; i++) {
        result.push_back(interval * (i + Sampler::random()));
    }
    return result;
}

vector<vec2> Sampler::sample2D(int amount, int sampleMethod) {
    switch (sampleMethod) {
        case RANDOM_SAMPLE: return random2D(amount);
        case JITTER_SAMPLE: return jitter2D(amount);
        default: throw std::invalid_argument("Non-Existing Sampling Method");
    }
}

vector<vec2> Sampler::sample2D(int amount, int sampleMethod, int weightMethod) {
    switch (sampleMethod) {
        case RANDOM_SAMPLE:
            switch (weightMethod) {
                case NO_WEIGHT: return random2D(amount);
                case GAUSSIAN_WEIGHT: return gaussianRandom2D(amount);
                case SHIRLEY_WEIGHT: return shirleyRandom2D(amount);
                default: throw std::invalid_argument("Non-Existing Weighting Method");
            }
            break;
        case JITTER_SAMPLE:
            switch (weightMethod) {
                case NO_WEIGHT: return jitter2D(amount);
                case GAUSSIAN_WEIGHT: return gaussianJitter2D(amount);
                case SHIRLEY_WEIGHT: return shirleyJitter2D(amount);
                default: throw std::invalid_argument("Non-Existing Weighting Method");
            }
            break;
        default: throw std::invalid_argument("Non-Existing Sampling Method");
    }
}

vector<vec2> Sampler::random2D(int amount) {
    vector<vec2> result;
    for (int i = 0; i < amount; i++) {
        uint64_t r = Random::next();
        uint32_t a = r >> 32;
        uint32_t b = r << 32 >> 32;
        result.push_back(vec2(random(a), random(b)));
    }
    return result;
}

vector<vec2> Sampler::gaussianRandom2D(int amount) {
    return gaussianWeight(random2D(amount));
}

vector<vec2> Sampler::shirleyRandom2D(int amount) {
    return shirleyWeight(random2D(amount));
}

vector<vec2> Sampler::jitter2D(int amount) {
    vector<vec2> result;
    int side = sqrt(amount);
    float interval = 1.0f / side;
    for (int x = 0; x < side; x++) {
        for (int y = 0; y < side; y++) {
            uint64_t r = Random::next();
            uint32_t a = r >> 32;
            uint32_t b = r << 32 >> 32;
            result.push_back(vec2(interval * (x + random(a)), interval * (y + random(b))));
        }
    }
    return result;
}

vector<vec2> Sampler::gaussianJitter2D(int amount) {
    return gaussianWeight(jitter2D(amount));
}

vector<vec2> Sampler::shirleyJitter2D(int amount) {
    return shirleyWeight(jitter2D(amount));
}
