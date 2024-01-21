#pragma once
#include "vec.h"
struct Ray;
struct HitData;
class GameObject
{
	float color;
	vec3 center;
public:
	inline vec3 getCenter() { return center; }
	GameObject(vec3 center,float color);
	float getColor();
	virtual HitData intersect(const Ray&) = 0;
	void move(vec3 vel);
	void setPos(vec3 newPos) {
		this->center = newPos;
	}
};