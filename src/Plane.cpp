#include "Plane.h"
#include "Ray.h"
Plane::Plane(vec3 pos, vec3 norm, float color):GameObject(pos,color),normal(norm) { }
HitData Plane::intersect(const Ray& r)
{
    HitData hit;
    hit.t = dot(getCenter() - r.origin, normal) / dot(r.dir, normal);
    hit.normal = normal;
    hit.color = getColor();
    hit.pos = r.getPosAt(hit.t);
    return hit;
}
