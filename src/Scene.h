#pragma once
#include "vec.h"
#include <vector>
class GameObject;
struct Ray;
class Scene
{
	std::vector<vec3> lights;
	std::vector<GameObject*> gameObjects;
	vec3 cameraPos{ 0.0f,0.0f,1.0f };
	float bgColor = 0.0f;
public:
	const std::vector<GameObject*>& getGameObjects() const;
	vec3 getCameraPos() const;
	void tick(long);
	float trace(const Ray&) const;
	Scene();
	~Scene();
};

