#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	class GameService
	{
	private:

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize(); //Handles game initialization.
		void initializeVariables(); //Handles game initialization
		void destroy(); // Handles cleanup tasks

	public:
		GameService(); //Constructor for initializing the GameService object
		~GameService(); //Destructor for cleaning up resources upon object deletion

		void ignite(); //initiates the game
		void update(); //updates the game logic and game state
		void render(); //renders each frame of the game
		bool isRunning(); //checks to see if the game is currently running

	};
}