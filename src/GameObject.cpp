#include "GameObject.h"

GameObject::GameObject(vec3 c,float col = 1.0f):center(c),color(col) {}
float GameObject::getColor() { return color; }
void GameObject::move(vec3 vel)
{
	center = center + vel;
}
