#pragma once
#include "GameObject.h"
class Torus : public GameObject
{
	float r, R;
public:
	Torus(vec3 pos,float smallR, float bigR);
	HitData intersect(const Ray&);
};

