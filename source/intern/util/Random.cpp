#include "util/Random.h"

uint64_t Random::s = DEFAULT_SEED;
uint64_t Random::cs = DEFAULT_SEED;

void Random::seed(int input) {
    s = input;
    cs = input;
}

uint64_t Random::next() {
    cs ^= cs >> 21;
    cs ^= cs << 35;
    cs ^= cs >> 4;
    return cs;
}

void Random::reset() {
    cs = s;
}
