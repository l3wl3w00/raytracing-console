#include "Sphere.h"
#include "Plane.h"
#include "Torus.h"
vec3 Scene::getCameraPos() const
{
	return cameraPos;
}

const std::vector<GameObject*>& Scene::getGameObjects() const { return gameObjects; };
#include <windows.h>
void Scene::tick(long frame)
{
	vec3 vel;
	if (GetAsyncKeyState(VK_UP)) {
		vel = vel + vec3(0,-0.1f,0);
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		vel = vel + vec3(-0.1f,0,0);
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		vel = vel + vec3(0,0.1f,0);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		vel = vel + vec3(0.1f,0,0);
	}
	if (GetAsyncKeyState(VK_SHIFT)) {
		vel = vel + vec3(0,0, 0.1f);
	}
	if (GetAsyncKeyState(VK_CONTROL)) {
		vel = vel + vec3(0,0, -0.1f);
	}
	gameObjects[0]->move(vel);
	//frame = 0;
	//gameObjects[0]->setPos(vec3(0.5f*sinf(frame*0.2), 0.1f, -1.5f + 0.5f*cosf(frame*0.2)) );
	//gameObjects[1]->setPos(vec3(-0.5f* sinf(frame*0.2), -0.1f, -1.5f - 0.5f* cosf(frame*0.2)));
	//gameObjects[1]->setPos(vec3(0.5f * sinf(frame * 0.2), -0.1f, -1.5f + 0.5f * cosf(frame * 0.2)));
	lights[0] = vec3(sinf(frame * 0.1)*0.5f, -1, -cosf(frame * 0.1))*0.5f;
}

Scene::Scene() {
	//gameObjects.push_back(new Torus(vec3(0, 0, 0), 0.1f, 0.2f));
	gameObjects.push_back(new Sphere(vec3(0.0f,0.0f,-1.0f),0.3f));
	gameObjects.push_back(new Plane(vec3(0,0.2f,0),vec3(0,-1,0)));
	gameObjects.push_back(new Sphere(vec3(0, -0.2f, 0), 0.15f));
	
	//gameObjects.push_back(new Sphere(vec3(0.5f, 0.0f, -1.0f), 0.3f));
	lights.push_back(vec3(0, -1,-1));
}

Scene::~Scene()
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

float Scene::trace(const Ray& ray) const
{
	
	HitData closestHit;
	for (auto gameObject : gameObjects) {
		HitData hit = gameObject->intersect(ray);
		// if the current hit was closer to the screen than the closest hit then it is the new one
		if (hit.t > 0 && (closestHit.t < 0 || hit.t < closestHit.t)) 
			closestHit = hit;
	}
	if (dot(ray.dir, closestHit.normal) > 0) closestHit.normal = closestHit.normal * (-1);
	if (closestHit.t < 0) { return bgColor; }
	Ray rayToLight( lights[0] - closestHit.pos, closestHit.pos + closestHit.normal * 0.0001f);
	float cosTheta = std::max<float>(dot(rayToLight.dir, closestHit.normal), 0.0f);
	float distanceToLight = length(closestHit.pos - lights[0]);
	return closestHit.color /*/(distanceToLight * distanceToLight);*/ * cosTheta+0.1f;
}