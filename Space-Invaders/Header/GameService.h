#pragma
#include<SFML/Graphics.hpp>
#include "../Header/ServiceLocator.h"
#include "../Header/GraphicService.h"

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