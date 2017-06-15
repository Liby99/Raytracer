#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Lambert.h"
#include "material/Luminance.h"
#include "object/Plane.h"
#include "object/Cube.h"
#include "object/Sphere.h"
#include "light/AreaLight.h"
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
    Sphere lgtsphere = Sphere(0.3);
    AreaLight area = AreaLight(lgtsphere);
    area.translateY(1);
    area.setCastShadow(true);
    scn.addLight(area);
    
    vec3 ori = vec3(0.3, 0.001, 0);
    vec3 dest = vec3(0, 1, 0);
    Ray ray = Ray(ori, dest - ori);
    Intersection its = Intersection(ray);
    its.setPosition(ori);
    for (int i = 0; i < 10; i++) {
        vec3 a = area.getToLightDirection(its);
        cout << a.x << " " << a.y << " " << a.z << endl;
    }
    
    float brightness = area.getBrightness(scn, its, ray, 0);
    
    cout << brightness << endl;
    
    return 0;
}
