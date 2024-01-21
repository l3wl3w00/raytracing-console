#include "Screen.h"
#include <iostream>
#include <stdlib.h>
#include "Ray.h"
Screen::Screen(int w, int h,Scene* scene) : sceneToDraw(scene) {
	width = w;
	height = h;
	screenArray = new Pixel*[h];
	for (size_t i = 0; i < w; i++){
		screenArray[i] = new Pixel[w];
	}
}
void Screen::update(long frame) {
	//cast a ray from each pixel
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			vec2 texCoord = vec2((float)x / width,(float)y/height);
			vec3 coordPos = vec3(texCoord * 2 - vec2(1,1), -1);
			Ray ray(coordPos - sceneToDraw->getCameraPos(),sceneToDraw->getCameraPos() );
			setColor(x,y, sceneToDraw->trace(ray));
		}
	}
}


#include <windows.h>

void Screen::clear()
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, {0,0});
}

void Screen::draw()
{
	clear();
	for (size_t h = 0; h < height; h++) {
		for (size_t w = 0; w < width; w++)
		{
			std::cout << screenArray[w][h].convertToCharacter();
		}
		std::cout << "\n";
	}
}

void Screen::setColor(int x, int y, float brightness)
{
	screenArray[x][y].setBrightness(brightness);
}

vec2 Screen::middle()
{
	return vec2(round(width / 2.0f),round(height / 2.0f));
}

Scene* Screen::getScreenToDraw()
{
	return sceneToDraw;
}


Screen::~Screen()
{
	for (int i = 0; i < height; i++)
	{
		delete[] screenArray[i]; 
	}
	delete[] screenArray;
	delete sceneToDraw;
}
