#pragma
#include<SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

class GameService
{
public:
	GameService();
	~GameService();


	void ignite();
	void update();
	void render();

	bool isRunning();

private:
	ServiceLocator* service_locator;
	sf::RenderWindow* game_window;
	void createGameService();
	void initializeVariables();
	void destroyGameService();


};