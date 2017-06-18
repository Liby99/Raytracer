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
    scn.setBackgroundColor(rgb(0.9, 0.9, 0.9));
    
    Lambert lambert = Lambert(rgb(1, 1, 1));
    
    Luminance lum = Luminance(rgb(1, 1, 1), 5);
    
    Plane ground = Plane();
    ground.setMaterial(lambert);
    scn.addObject(ground);
    
    float coef = 30;
    float ior = 2.4;
    
    Dielectric red = Dielectric();
    red.setAbsorptionCoef(coef);
    red.setIor(ior);
    red.setAbsorptionColor(rgb(1.0, 0.3, 0.3));
    
    Dielectric orange = Dielectric();
    red.setAbsorptionCoef(coef);
    orange.setIor(ior);
    orange.setAbsorptionColor(rgb(1.0, 0.7, 0));
    
    Dielectric green = Dielectric();
    red.setAbsorptionCoef(coef);
    green.setIor(ior);
    green.setAbsorptionColor(rgb(0.0, 1.0, 0.0));
    
    Dielectric blue = Dielectric();
    red.setAbsorptionCoef(coef);
    blue.setIor(ior);
    blue.setAbsorptionColor(rgb(0, 1, 1.0));
    
    Dielectric purple = Dielectric();
    red.setAbsorptionCoef(coef);
    purple.setIor(ior);
    purple.setAbsorptionColor(rgb(1.0, 0, 1));
    
    vector<Material *> mtls;
    mtls.push_back(&red);
    mtls.push_back(&orange);
    mtls.push_back(&green);
    mtls.push_back(&blue);
    mtls.push_back(&purple);
    
    BoxTreeObject diamond = BoxTreeObject();
    
    diamond.addVertex(vec3(0, 0, 0));
    diamond.addVertex(vec3(0, 0.15, 0.2));
    diamond.addVertex(vec3(0.2, 0, 0.2));
    diamond.addVertex(vec3(0, -0.15, 0.2));
    diamond.addVertex(vec3(-0.2, 0, 0.2));
    diamond.addVertex(vec3(0, 0, 0.7));
    
    diamond.addTriangle(0, 2, 1);
    diamond.addTriangle(0, 1, 4);
    diamond.addTriangle(0, 4, 3);
    diamond.addTriangle(0, 3, 2);
    diamond.addTriangle(5, 1, 2);
    diamond.addTriangle(5, 4, 1);
    diamond.addTriangle(5, 3, 4);
    diamond.addTriangle(5, 2, 3);
    
    diamond.initiate();
    diamond.rotateY(-26, 0);
    diamond.rotateY(116, 120);
    
    diamond.rotateZ(60, 0);
    diamond.rotateZ(0, 120);
    
    diamond.rotateX(12, 0);
    diamond.rotateX(0, 120);
    
    CircularCloner cloner = CircularCloner(diamond, 0.2, 5);
    cloner.enableSeparateMaterial();
    cloner.setMaterial(mtls);
    
    cloner.translateY(1, 0);
    cloner.translateY(-0.8, 120);
    cloner.translateX(1, 0);
    cloner.translateX(0, 120);
    
    cloner.rotateX(60, 0);
    cloner.rotateX(-60, 120);
    cloner.rotateY(600, 0);
    cloner.rotateY(0, 120);
    cloner.rotateZ(27, 0);
    cloner.rotateZ(0, 120);
    
    cloner.setRadius(-0.1, 0);
    cloner.setRadius(0.15, 120);
    
    scn.addObject(cloner);
    
    Camera cam;
    cam.lookAt(vec3(0.2, 1.3, 0.2), vec3(0, 0.3, 0));
    cam.setFovy(80.0f);
    cam.setResolution(720, 480);
    cam.enableSampling();
    cam.setSamplingAmount(sample);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);
    
    // cam.enableDepthOfField();
    // cam.setFocalDistance(1.3);
    // cam.setAperture(0.1);
    
    cam.enableMotionBlur();
    cam.setShutterSpeed(1);
    
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
    
    int step = 1;
    for (int i = 120; i >= 0; i -= step) {
        cout << "Frame " << i << " " << endl;
        Image img1 = cam.render(scn, i);
        Bitmap::saveImage(img1, ("p5_" + to_string(i) + ".bmp").c_str());
        cout << endl;
    }
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    return 0;
}
