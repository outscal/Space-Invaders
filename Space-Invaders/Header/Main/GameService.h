#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	enum class GameState //create the enum
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};
	
	class GameService
	{
	private:
		static GameState current_state; // what is that static keyword??? We will discuss this later.
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize(); //Handles game initialization.
		void initializeVariables(); //Handles game initialization
		void destroy(); // Handles cleanup tasks

		void showMainMenu();

	public:
		GameService(); //Constructor for initializing the GameService object
		~GameService(); //Destructor for cleaning up resources upon object deletion

		void ignite(); //initiates the game
		void update(); //updates the game logic and game state
		void render(); //renders each frame of the game
		bool isRunning(); //checks to see if the game is currently running

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}