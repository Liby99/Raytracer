#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Lambert.h"
#include "material/Luminance.h"
#include "object/Plane.h"
#include "object/Cube.h"
#include "object/Sphere.h"
#include "light/AreaLight.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
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
    
    Scene scn;
    PathTracer pt = PathTracer(bounce);
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    Lambert lam = Lambert(rgb(0.3f, 0.3f, 0.3f));
    Lambert white = Lambert(rgb(0.9, 0.9, 0.9));
    
    Plane ground = Plane();
    ground.setMaterial(lam);
    scn.addObject(ground);
    
    Sphere sphere = Sphere(0.3);
    sphere.translateY(0.3);
    sphere.setMaterial(white);
    scn.addObject(sphere);
    
    // Cube cube = Cube(0.2, 0, 0.2);
    // cube.translateY(1);
    Sphere lgtsphere = Sphere(0.05);
    AreaLight area = AreaLight(lgtsphere);
    area.setIntensity(10);
    area.translateY(1);
    area.setCastShadow(true);
    scn.addLight(area);
    // PointLight ptlgt = PointLight(rgb(1, 1, 1), vec3(0, 1, 0));
    // ptlgt.setCastShadow(true);
    // scn.addLight(ptlgt);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(2, 1.3, 2), vec3(0, 0, 0));
    cam.setFovy(40.0f);
    cam.setResolution(800, 600);
    cam.enableSampling();
    cam.setSamplingAmount(sample);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);
    
    // Time setup
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
    Bitmap::saveImage(image, "arealight.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    return 0;
}
