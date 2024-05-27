#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
namespace Main 
{
	//class ServiceLocator;
	//using namespace Global;
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};
	class GameService
	{
	private:
		static GameState current_state;
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		void Initialize();
		void InitializeVariables(); // Handles game initialization.
		void Destroy();			// Handles cleanup tasks.
	public:
		GameService();			// Constructor for initializing the GameService object.
		~GameService();	    // Destructor for cleaning up resources upon object deletion.

		void Ignite();			// Initiates the game.
		void Update();			// Updates the game logic and game state.
		void Render();			// Renders each frame of the game.
		bool isRunning();		// Checks if the game is currently running.

		void ShowMainMenu();
		/*void ShowGameplayScreen();
		void ShowPauseMenu();*/

		//Getters and setters
		static void SetGameState(GameState new_state);
		static GameState GetGameState();
	};

}


