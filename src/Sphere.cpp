#include "Sphere.h"
#include "general.h"

Sphere::Sphere(vec3 c, float r, float color) :radius(r), GameObject(c,color) {}
HitData Sphere::intersect(const Ray& ray)
{
    //Ray rotatedRay = r;
    //rotate(rotatedRay, s.currentRotation);
    HitData hit;
    vec3 shiftedOrigin = ray.origin - getCenter();
    bool isIntersecting = false;
    vec2 bothT = solveQuadratic(
        dot(ray.dir, ray.dir),
        2.0f * dot(shiftedOrigin, ray.dir),
        dot(shiftedOrigin, shiftedOrigin) - radius * radius,
        isIntersecting
    );
    if (!isIntersecting) {
        return hit;
    }
    hit.t = (bothT.y > 0) ? bothT.y : bothT.x;
    hit.pos = ray.getPosAt(hit.t);
    hit.normal = (hit.pos - getCenter()) * (1.0f / radius);
    hit.color = getColor();
    return hit;
}