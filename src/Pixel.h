#pragma once
#include <string>
#include <vector>
class Pixel
{
	float brightness;
	static std::vector <std::string* > characterMap;
public:
	static void fillCharacterMap(std::string);
	static void freeCharacterMap();

	Pixel();
	Pixel(float bright);
	const char* convertToCharacter();
	void setBrightness(float b);
};

