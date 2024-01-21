#include "Pixel.h"
#include "general.h"
#include <string>
#include <iostream>
Pixel::Pixel(float b) {
	this->brightness = b;
}
void Pixel::fillCharacterMap(std::string characters)
{
	int idx = 0;
	for (int i = 1; i < characters.length(); ++i) {
		char current = characters[i];
		char prev = characters[i-1];
		auto s1 = new std::string(1, prev);
		*s1 += prev;
		auto s2 = new std::string(1, current);
		*s2 += prev;
		characterMap.push_back(s1);
		characterMap.push_back(s2);
		idx++;
	}
	auto s = new std::string(1, characters[characters.length()-1]);
	*s += characters[characters.length() - 1];
	characterMap.push_back(s);
}

void Pixel::freeCharacterMap() {
	for (auto s : characterMap) {
		delete s;
	}
}
Pixel::Pixel() {
	this->brightness = 1.0f;
}
const char* Pixel::convertToCharacter() {
	int idx = 0;
	float interval = 1.0f / characterMap.size();
	for (float i = 0; i < 1.0f; i += interval) {
		if (brightness <= i) return characterMap[idx]->c_str();
		++idx;
	}
	//for (auto c : characterMap) {
	//	if (brightness <= c.first) return c.second;
	//}
	return characterMap[characterMap.size()-1]->c_str();
}

void Pixel::setBrightness(float b) { brightness = b; }