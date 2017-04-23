#include "scene/Scene.h"
#include "material/Diffuse.h"
#include "material/Specular.h"
#include "object/Plane.h"
#include "object/Cylinder.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"

int main() {
    Scene scene;
    scene.setBackgroundColor(Color(0.8, 0.8, 1));
    
    Diffuse diffuse = Diffuse(Color(1, 1, 1));
    Specular specular = Specular(Color(1, 1, 1));
    
    Plane ground = Plane();
    ground.addMaterial(diffuse);
    scene.addObject(ground);
    
    Cylinder cy1 = Cylinder();
    cy1.translateY(0.5);
    cy1.addMaterial(diffuse);
    cy1.addMaterial(specular);
    scene.addObject(cy1);
    
    Cylinder cy2 = Cylinder(Orientable::Z_POSITIVE, 2, 0.2);
    cy2.rotateY(20);
    cy2.translateY(0.2);
    cy2.translateX(1);
    cy2.addMaterial(diffuse);
    cy2.addMaterial(specular);
    scene.addObject(cy2);
    
    Cylinder cy3 = Cylinder(Orientable::X_POSITIVE, 1, 0.15);
    cy3.translateY(0.15);
    cy3.translateX(-0.5);
    cy3.translateZ(1);
    cy3.addMaterial(diffuse);
    cy3.addMaterial(specular);
    scene.addObject(cy3);
    
    PointLight pl = PointLight(Color(1, 0.5, 0.5), vec3(-2, 3, 2));
    pl.setIntensity(5);
    pl.setCastShadow(true);
    scene.addLight(pl);
    
    DirectionalLight dl = DirectionalLight(Color(1, 1, 1), vec3(-1, -1, 1));
    dl.setIntensity(0.8);
    dl.setCastShadow(true);
    scene.addLight(dl);
    
    Camera cam = Camera();
    cam.lookAt(vec3(2.5, 1.5, 2.5), vec3(0, 0, 0));
    cam.setFovy(45);
    
    Bitmap bmp = cam.render(scene);
    bmp.saveImage("project1scene2.bmp");
}
