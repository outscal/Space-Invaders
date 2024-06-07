#pragma
#include<SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	class ServiceLocator;

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
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		void createGameService();
		void initializeVariables();
		void destroyGameService();


	};
}

