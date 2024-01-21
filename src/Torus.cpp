#include "Torus.h"
#include "Ray.h"
#include "general.h"
float minimalPositive(float solutions[5], int n) {
    float max = solutions[0];
    for (int i = 0; i < n; i++) {
        if (solutions[i] > max) max = solutions[i];
    }

    float min = max;
    for (int i = 0; i < n; i++) {
        if (solutions[i] < 0.0001f) continue;
        if (solutions[i] < min) min = solutions[i];
    }

    return min;
}
Torus::Torus(vec3 pos,float smallR, float bigR):GameObject(pos,1.0f) {
    r = smallR;
    R = bigR;
}
HitData Torus::intersect(const Ray& ray)
{
    HitData hit;
    vec3 o = ray.origin - getCenter();
    vec3 d = ray.dir;
    float dotDir = dot(ray.dir, ray.dir);
    float dotOrigin = dot(o, o);
    float dotDirOrigin = dot(o, ray.dir);
    float rAndR = (r * r + R * R);
    // http://blog.marcinchwedczuk.pl/ray-tracing-torus
    float c4 = pow(dotDir, 2);
    float c3 = 4* dotDir * dotDirOrigin;
    float c2 = 2*dotDir*(dotOrigin - rAndR)+4*pow(dotDirOrigin,2) + 4*R*R*d.y*d.y;
    float c1 = 4*(dotOrigin - rAndR)*(dotDirOrigin)+8*R*R*o.y*d.y;
    float c0 = pow(dotOrigin - rAndR,2)- 4*R*R*(r*r - o.y*o.y);
    float coeffs[5] = { c0,c1,c2,c3,c4 };
    float solutions[4];
    int numberOfSolutions = solveQuartic(coeffs,solutions);
    if (numberOfSolutions == 0) return hit;
    
    //float tMin = 1000.0f;// solutions[0];
    //for (int i = 0; i < numberOfSolutions; i++){
    //    if (solutions[i] < 0) continue;
    //    if (solutions[i] < tMin) tMin = solutions[i];
    //}
    hit.t = minimalPositive(solutions,numberOfSolutions);
    hit.color = getColor();
    hit.pos = ray.getPosAt(hit.t);

    float alpha = (R) / sqrtf(hit.pos.x * hit.pos.x + hit.pos.y * hit.pos.y);
    auto paramSquared = rAndR;
    auto sumSquared = dot(hit.pos,hit.pos);

    vec3 tmp = vec3(
        4.0f * hit.pos.x * (sumSquared - paramSquared),
        4.0f * hit.pos.y * (sumSquared - paramSquared + 2.0f * R * R),
        4.0f * hit.pos.z * (sumSquared - paramSquared));

    hit.normal = normalize(tmp);//hit.pos - alpha*vec3(hit.pos.x,hit.pos.y,0));
    hit.normal = hit.normal + getCenter();
    return hit;
}
