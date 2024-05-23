#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"


class GameService
{
private:
	ServiceLocator *service_locator;
	sf::RenderWindow *game_window;
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
};

