#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Dielectric.h"
#include "material/Luminance.h"
#include "material/Lambert.h"
#include "object/Sphere.h"
#include "object/Plane.h"
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
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    Lambert grey = Lambert(rgb(0.8, 0.8, 0.8));
    Dielectric trans = Dielectric();
    trans.setAbsorptionColor(rgb(1, 1, 1));
    trans.setIor(Dielectric::WATER_IOR);
    Luminance lum = Luminance(Color::WHITE, 10);
    
    Plane ground = Plane();
    ground.setMaterial(grey);
    scn.addObject(ground);
    
    Cube cube = Cube(1, 0.01, 1);
    cube.translateY(3);
    cube.setMaterial(lum);
    scn.addObject(cube);
    
    Sphere sphere = Sphere(1);
    sphere.translateY(1);
    sphere.setMaterial(trans);
    scn.addObject(sphere);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(3, 1.5, 3), vec3(0, 0, 0));
    cam.setFovy(75.0f);
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
