
#include "App.h"
App App::instance;
std::vector<std::string*> Pixel::characterMap;
int main()
{
    Pixel::fillCharacterMap(" .:;�$#");
    App::getInstance().run();
    Pixel::freeCharacterMap();
}