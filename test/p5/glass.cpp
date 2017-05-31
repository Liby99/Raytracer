#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Dielectric.h"
#include "material/Luminance.h"
#include "material/Lambert.h"
#include "object/BoxTreeObject.h"
#include "object/InstanceObject.h"
#include "object/Cube.h"
#include "light/PointLight.h"
#include "camera/Camera.h"
#include "image/Bitmap.h"

int BOUNCE = 10;
int SAMPLE = 100;

int main(int argc, char * argv[]) {
    
    int sample = SAMPLE;
    int bounce = BOUNCE;
    if (argc >= 2) {
        sample = atoi(argv[1]);
    }
    if (argc >= 3) {
        bounce = atoi(argv[2]);
    }
    
    // Initiate Scene
    Scene scn;
    PathTracer pt = PathTracer(bounce);
    // pt.disableLight();
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    // Initiate Material
    Lambert white = Lambert();
    Lambert red = Lambert(rgb(1, 0, 0));
    Lambert green = Lambert(rgb(0, 1, 0));
    Dielectric trans = Dielectric();
    Luminance lum = Luminance();
    lum.setIntensity(5);
    
    // Setup room
    Cube flr = Cube(10, 0.1, 10);
    flr.setMaterial(white);
    scn.addObject(flr);
    
    // Create dragon
    BoxTreeObject dragon = BoxTreeObject("res/dragon.ply");
    dragon.translateY(0.1);
    dragon.setMaterial(trans);
    scn.addObject(dragon);
    
    // Create Light
    // Cube light = Cube(2, 0.1, 2);
    // light.translateY(4.8);
    // light.setMaterial(lum);
    // scn.addObject(light);
    // PointLight light = PointLight(Color::WHITE, vec3(0, 4.8, 0));
    // light.setIntensity(3);
    // scn.addLight(light);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(0, 2.5, 2.3), vec3(0, 2.5, 0));
    cam.setFovy(80.0f);
    cam.setResolution(800, 600);
    cam.enableSampling();
    cam.setSamplingAmount(sample);
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
    Bitmap::saveImage(image, "transparency.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    return 0;
}
