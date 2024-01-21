#include "Ray.h"
HitData::HitData() :t(-1),color(0) {}
Ray::Ray(vec3 d, vec3 o){
	dir = normalize(d);
	origin = o;
}
vec3 Ray::getPosAt(float t) const { return origin + dir * t; }