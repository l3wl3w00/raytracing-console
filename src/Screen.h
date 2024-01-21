#pragma once
#include "Pixel.h"
#include "Scene.h"
class Screen
{
	int width;
	int height;
	Pixel** screenArray;
	Scene* sceneToDraw;
public:
	Screen(int w, int h, Scene* scene);
	void update(long);
	void clear();
	void draw();
	void setColor(int x, int y, float brightness);
	vec2 middle();
	Scene* getScreenToDraw();
	~Screen();
};

