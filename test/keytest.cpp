#include <iostream>

#include "util/Math.h"
#include "animation/Animatable.h"

using namespace std;

int main() {
    Animatable<float> var;
    var.set(0, -0.5);
    var.set(1, 0.5);
    cout << var.get(0) << endl;
    cout << var.get(0.25) << endl;
    cout << var.get(0.5) << endl;
    cout << var.get(0.75) << endl;
    cout << var.get(1) << endl;
}
