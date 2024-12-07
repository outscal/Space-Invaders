#include "../header/GraphicService.h"
void GraphicService::initialize()
{
	game_window = createGameWindow();
	game_window->setFramerateLimit(frame_rate);
}