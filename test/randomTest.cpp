#include "util/Random.h"

#include <iostream>

using namespace std;

int main() {
    
    cout << "Generate three random numbers: " << endl;
    uint64_t a = Random::next();
    uint64_t b = Random::next();
    uint64_t c = Random::next();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    
    cout << "Reset Random: Should generate the same three random numbers: " << endl;
    Random::reset();
    uint64_t e = Random::next();
    uint64_t f = Random::next();
    uint64_t g = Random::next();
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    cout << "g: " << g << endl;
    
    cout << "Seed Current Time: Should generate completely random numbers: " << endl;
    Random::seed(time(0));
    uint64_t h = Random::next();
    uint64_t i = Random::next();
    uint64_t j = Random::next();
    cout << "h: " << h << endl;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
}
