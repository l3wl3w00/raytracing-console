#pragma once
#include "Scene.h"
struct HitData {
	float t;
	vec3 normal;
	vec3 pos;
	float color;
	HitData();
};

struct Ray
{
	vec3 dir;
	vec3 origin;
	Ray(vec3 d, vec3 o);
	vec3 getPosAt(float t) const;
};

