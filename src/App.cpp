#include "App.h"
App::App():screen(50, 50, new Scene()) {
	currentScene = screen.getScreenToDraw();
	running = true;
}
App App::getInstance() { return instance; }
void App::stop()
{
	running = false;
}

void App::run()
{
	while (running) {
		currentScene->tick(frame);
		screen.update(frame);
		screen.draw();
		++frame;
	}
}
