#include "scene/Scene.h"
#include "util/Color.h"
#include "light/DirectionalLight.h"
#include "light/SpotLight.h"
#include "material/Diffuse.h"
#include "material/Specular.h"
#include "object/Plane.h"
#include "object/Cube.h"
#include "object/MeshCube.h"
#include "camera/AntiAliasingCamera.h"
#include "util/Bitmap.h"

int main() {
    Scene scene;
    scene.setBackgroundColor(Color(0.8, 0.9, 1));
    
    Diffuse diffuse = Diffuse(Color(1, 1, 1));
    Specular specular = Specular(Color(1, 1, 1));
    
    Plane ground;
    ground.addMaterial(diffuse);
    scene.addObject(ground);
    
    Cube cube = Cube(0.5, 0.5, 0.5);
    cube.translateY(0.25);
    cube.addMaterial(diffuse);
    cube.addMaterial(specular);
    scene.addObject(cube);
    
    Cube cube2 = Cube(0.2, 0.2, 1.5);
    cube2.translateY(0.1);
    cube2.translateX(0.8);
    cube2.rotateY(40);
    cube2.addMaterial(diffuse);
    cube2.addMaterial(specular);
    scene.addObject(cube2);
    
    Cube cube3 = Cube(0.4, 0.4, 0.4);
    cube3.translateY(0.2);
    cube3.translateZ(1);
    cube3.rotateY(75);
    cube3.addMaterial(diffuse);
    cube3.addMaterial(specular);
    scene.addObject(cube3);
    
    DirectionalLight dl = DirectionalLight(Color(1, 1, 1), vec3(1, -1, -1));
    dl.setCastShadow(true);
    dl.setIntensity(0.3);
    scene.addLight(dl);
    
    SpotLight sl = SpotLight(Color(1, 1, 1), vec3(2, 2, 0), vec3(0, 0, 0), 45);
    sl.setIntensity(3);
    sl.setCastShadow(true);
    scene.addLight(sl);
    
    AntiAliasingCamera cam = AntiAliasingCamera();
    cam.lookAt(vec3(2.5, 0.75, 2.5), vec3(0, 0, 0));
    cam.setFovy(45);
    
    cout << "light: " << scene.lightAmount() << endl;
    cout << "object: " << scene.objectAmount() << endl;
    
    Bitmap bmp = cam.render(scene);
    bmp.saveImage("project1scene4aa.bmp");
}
