#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Dielectric.h"
#include "material/Luminance.h"
#include "material/Lambert.h"
#include "object/Sphere.h"
#include "object/Plane.h"
#include "object/Cube.h"
#include "object/Sun.h"
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
    trans.setAbsorptionColor(rgb(0.3, 1, 0.3));
    trans.setIor(Dielectric::GLASS_IOR);
    Luminance lum = Luminance(Color::WHITE, 20);
    
    Plane ground = Plane();
    ground.setMaterial(grey);
    scn.addObject(ground);
    
    // Cube cube = Cube(1, 0.01, 1);
    // cube.translateY(3);
    // cube.setMaterial(lum);
    // scn.addObject(cube);
    
    Sphere sphere = Sphere(1);
    sphere.translateY(1);
    sphere.setMaterial(trans);
    scn.addObject(sphere);
    
    // Cube glass = Cube(2, 2, 0.1);
    // glass.translateY(1);
    // glass.rotateX(24);
    // glass.rotateY(12);
    // glass.setMaterial(trans);
    // scn.addObject(glass);
    
    Sun sun = Sun(vec3(-1, 1, -1), 10);
    sun.setMaterial(lum);
    scn.addObject(sun);
    
    // Cube normal = Cube(1.3, 1.7, 1);
    // normal.translateY(0.85);
    // normal.translateZ(-1);
    // normal.rotateY(36);
    // normal.setMaterial(grey);
    // scn.addObject(normal);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(3, 1.5, 3), vec3(0, 1.5, 0));
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
