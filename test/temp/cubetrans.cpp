#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Ashikhmin.h"
#include "material/Lambert.h"
#include "material/Dielectric.h"
#include "material/Luminance.h"
#include "material/Metal.h"
#include "object/GridCloner.h"
#include "object/CircularCloner.h"
#include "object/Cube.h"
#include "object/Sphere.h"
#include "object/Plane.h"
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
    scn.setBackgroundColor(rgb(0, 0, 0));
    
    Lambert lambert = Lambert(rgb(0.5, 0.5, 0.5));
    Luminance lum = Luminance(rgb(1, 1, 1), 10);
    
    Dielectric trans = Dielectric();
    trans.setIor(2.4);
    trans.setAbsorptionColor(rgb(1.0, 1.0, 1.0));
    
    Cube lgt = Cube(1.0, 0.01, 1.0);
    lgt.translateY(2);
    lgt.setMaterial(lum);
    scn.addObject(lgt);
    
    Cube cube = Cube(0.5, 0.5, 0.5);
    GridCloner cloner = GridCloner(cube, 1.2, 1, 1.2, 2, 1, 2);
    cloner.translateY(0.6);
    cloner.setMaterial(trans);
    scn.addObject(cloner);
    
    Plane ground = Plane();
    ground.setMaterial(lambert);
    ground.translateY(-0.5);
    scn.addObject(ground);
    
    Camera cam;
    cam.lookAt(vec3(1, 0.8, 1), vec3(0, 0, 0));
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
    Bitmap::saveImage(image, "glasscube.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    return 0;
}
