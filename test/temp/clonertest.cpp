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
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    Lambert lambert = Lambert(rgb(0.5, 0.5, 0.5));
    Metal metal = Metal(rgb(0.8, 0.5, 0.5));
    Dielectric trans = Dielectric();
    trans.setIor(Dielectric::DIAMOND_IOR);
    trans.setAbsorptionColor(rgb(0.5, 0.8, 0.6));
    Ashikhmin ashik;
    ashik.setDiffuseLevel(0.0f);
    ashik.setSpecularLevel(1.0f);
    ashik.setSpecularColor(Color(0.95f, 0.7f, 0.3f));
    ashik.setRoughness(1.0f, 1000.0f);
    Luminance lum = Luminance(rgb(1, 1, 1), 10);
    
    vector<Material *> mtls;
    mtls.push_back(&lambert);
    mtls.push_back(&metal);
    mtls.push_back(&trans);
    mtls.push_back(&ashik);
    mtls.push_back(&lum);
    
    Cube cube = Cube(0.5, 0.5, 0.5);
    
    CircularCloner cloner = CircularCloner(cube);
    cloner.enableSeparateMaterial();
    cloner.setMaterial(mtls);
    cloner.setMaterial(ashik);
    scn.addObject(cloner);
    
    Plane ground = Plane();
    ground.setMaterial(lambert);
    ground.translateY(-0.5);
    scn.addObject(ground);
    
    Camera cam;
    cam.lookAt(vec3(1, 1, 1), vec3(0, 0, 0));
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
