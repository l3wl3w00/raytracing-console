#pragma once
#include "GameObject.h"
#include "Ray.h"
class Sphere:public GameObject
{
	float radius;
public:
	Sphere(vec3 c, float r, float color = 1.0f);
	HitData intersect(const Ray&);
	
};

