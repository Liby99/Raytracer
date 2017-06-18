#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Ashikhmin.h"
#include "material/Lambert.h"
#include "material/Dielectric.h"
#include "material/Luminance.h"
#include "material/Metal.h"
#include "object/BoxTreeObject.h"
#include "object/GridCloner.h"
#include "object/CircularCloner.h"
#include "object/Cube.h"
#include "object/Sphere.h"
#include "object/Plane.h"
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
    scn.setBackgroundColor(rgb(0.8, 0.8, 0.8));
    
    Lambert lambert = Lambert(rgb(0.8, 0.8, 0.8));
    
    Dielectric red = Dielectric();
    red.setIor(2.4);
    red.setAbsorptionColor(rgb(1.0, 0.3, 0.3));
    
    Dielectric orange = Dielectric();
    orange.setIor(2.4);
    orange.setAbsorptionColor(rgb(1.0, 0.7, 0.3));
    
    Dielectric green = Dielectric();
    green.setIor(2.4);
    green.setAbsorptionColor(rgb(0.3, 1.0, 0.4));
    
    Dielectric blue = Dielectric();
    blue.setIor(2.4);
    blue.setAbsorptionColor(rgb(0.2, 0.5, 1.0));
    
    Dielectric purple = Dielectric();
    purple.setIor(2.4);
    purple.setAbsorptionColor(rgb(1.0, 0.2, 0.8));
    
    vector<Material *> mtls;
    mtls.push_back(&red);
    mtls.push_back(&orange);
    mtls.push_back(&green);
    mtls.push_back(&blue);
    mtls.push_back(&purple);
    
    Cube lgtcube = Cube(0.1, 0.01, 0.1);
    lgtcube.translateY(3);
    AreaLight lgt = AreaLight(lgtcube);
    lgt.setIntensity(10);
    scn.addObject(lgt);
    
    BoxTreeObject diamond = BoxTreeObject();
    
    diamond.addVertex(vec3(0, 0, 0));
    diamond.addVertex(vec3(0, 0.4, 1));
    diamond.addVertex(vec3(1, 0, 1));
    diamond.addVertex(vec3(0, -0.4, 1));
    diamond.addVertex(vec3(-1, 0, 1));
    diamond.addVertex(vec3(0, 0, 3.5));
    
    diamond.addTriangle(0, 2, 1);
    diamond.addTriangle(0, 1, 4);
    diamond.addTriangle(0, 4, 3);
    diamond.addTriangle(0, 3, 2);
    diamond.addTriangle(5, 1, 2);
    diamond.addTriangle(5, 4, 1);
    diamond.addTriangle(5, 3, 4);
    diamond.addTriangle(5, 2, 3);
    
    diamond.initiate();
    diamond.rotateY(90);
    
    CircularCloner cloner = CircularCloner(diamond, 0.75, 5);
    cloner.translateY(0.6);
    cloner.enableSeparateMaterial();
    cloner.setMaterial(mtls);
    scn.addObject(cloner);
    
    Plane ground = Plane();
    ground.setMaterial(lambert);
    ground.translateY(-1);
    scn.addObject(ground);
    
    Camera cam;
    cam.lookAt(vec3(3, 4, 3), vec3(0, 0.6, 0));
    cam.setFovy(75.0f);
    cam.setResolution(720, 480);
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
