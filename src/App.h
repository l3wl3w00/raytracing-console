#pragma once
#include "Screen.h"
class App
{
	long frame = 0;
	bool running;
	Screen screen;
	static App instance;
	Scene* currentScene;
	App();
public:
	static App getInstance();
	void run();
	void stop();
	
};

