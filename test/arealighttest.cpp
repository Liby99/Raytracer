#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "light/AreaLight.h"
#include "util/BoundingBox.h"
#include "camera/Camera.h"
#include "image/Bitmap.h"

#include <iostream>

using namespace std;

int main() {
    Scene scn;
    PathTracer pt;
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(rgb(0.7, 0.8, 0.9));
    
    AreaLight al = AreaLight(Color::WHITE, 1, 1, Orientable::Z_NEGATIVE);
    
    scn.addLight(al);
    
    cout << (string)(al.getColor()) << endl;
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(0, 0, 2.3f), vec3(0.0f, 0.0f, 0.0f), vec3(0, 1, 0));
    cam.setResolution(720, 480);
    cam.setFovy(75.0f);
    
    cam.enableSampling();
    cam.setSamplingAmount(4);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);
    
    time_t curr = time(0);
    cam.onRender([curr](int i, int j, Color c, float progress) {
        int barWidth = 80;
        cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        cout << "] " << int(progress * 100.0) << "%, (" << time(0) - curr << "s)\r";
        cout.flush();
    });
    
    // Render image
    Image image = cam.render(scn);
    Bitmap::saveImage(image, "arealight_test.bmp");
    
    cout << endl << "Total Time Elapsed: " << time(0) - curr << "s" << endl;
    return 0;
}
