#include "material/Dielectric.h"

const float Dielectric::DEFAULT_IOR = 1;
const float Dielectric::DEFAULT_ABSORPTION_COEF = 1;
const Color Dielectric::DEFAULT_ABSORPTION_COLOR = Color(1, 1, 1);
const Color Dielectric::DEFAULT_SPECULAR_COLOR;

const float Dielectric::AIR_IOR = 1.0003;
const float Dielectric::WATER_IOR = 1.3333;
const float Dielectric::ICE_IOR = 1.309;
const float Dielectric::GLASS_IOR = 1.6;
const float Dielectric::DIAMOND_IOR = 2.42;

Dielectric::Dielectric() : Material() {
    setIor(DEFAULT_IOR);
    setAbsorptionCoef(DEFAULT_ABSORPTION_COEF);
    setAbsorptionColor(DEFAULT_ABSORPTION_COLOR);
    setSpecularColor(DEFAULT_SPECULAR_COLOR);
}

float Dielectric::getIor() {
    return ior;
}

void Dielectric::setIor(float ior) {
    this->ior = ior;
}

float Dielectric::getAbsorptionCoef() {
    return absorptionCoef;
}

void Dielectric::setAbsorptionCoef(float coef) {
    this->absorptionCoef = coef;
}

Color Dielectric::getAbsorptionColor() {
    return absorptionColor;
}

void Dielectric::setAbsorptionColor(Color c) {
    this->absorptionColor = c;
}

Color Dielectric::getSpecularColor() {
    return specularColor;
}

void Dielectric::setSpecularColor(Color c) {
    this->specularColor = c;
}

pair<Ray, Color> Dielectric::generateSample(Intersection & intersection, vec2 sample) {
    
    // First cache the incoming ray
    Ray & inray = intersection.getRay();
    vec3 indir = inray.getDirection();
    vec3 pos = intersection.getPosition();
    vec3 normal = intersection.getNormal();
    
    // Then cache all the useful data
    float n1 = AIR_IOR;
    float n2 = ior;
    if (inray.isInside()) {
        swap(n1, n2);
    }
    float r0 = pow((n2 - n1) / (n2 + n1), 2);
    
    // Decide transmit or reflect
    if (Sampler::random() < r0) {
        
        // Then reflect
        vec3 outdir = indir + 2.0f * dot(indir, normal) * normal;
        Ray out = Ray(pos, outdir, inray.getDepth() + 1, inray.isInside());
        return make_pair(out, specularColor * r0);
    }
    else {
        
        // Then transmit
        float ct1 = dot(indir, normal);
        float ct2 = n1 * ct1 / n2;
        vec3 orth = cross(-indir, normal);
        vec3 outdir = mat3(Transform::rotate(glm::degrees(ct2), -orth)) * (-normal);
        Ray out = Ray(pos, outdir, inray.getDepth() + 1, !inray.isInside());
        
        // Check the inside or outside to determine color
        Color color;
        if (inray.isInside()) {
            vec3 diff = pos - inray.getOrigin();
            float dist = sqrt(dot(diff, diff));
            float s = -absorptionCoef * dist;
            color.setR(exp(s * (1.0f - absorptionColor.getR())));
            color.setG(exp(s * (1.0f - absorptionColor.getG())));
            color.setB(exp(s * (1.0f - absorptionColor.getB())));
        }
        else {
            color = Color::WHITE;
        }
        
        return make_pair(out, color);
    }
}
