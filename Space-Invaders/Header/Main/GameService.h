#pragma
#include<SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{

	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};

	class GameService
	{
	public:

		GameService();
		~GameService();


		void ignite();
		void update();
		void render();

		bool isRunning();

		static GameState getGameState();
		static void setGameState(GameState state);

		void showMainMenu();

	private:
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		void createGameService();
		void initializeVariables();
		void destroyGameService();

		static GameState currentState;



	};
}

