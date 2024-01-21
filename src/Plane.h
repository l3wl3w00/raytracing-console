#pragma once
#include "GameObject.h"
class HitData;
class Plane:public GameObject
{
	vec3 normal;
public:
	Plane(vec3 pos, vec3 normal, float color = 0.5f);
	HitData intersect(const Ray&);
};

