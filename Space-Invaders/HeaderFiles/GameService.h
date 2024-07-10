#pragma once
#include <SFML/Graphics.hpp>
#include"../HeaderFiles/ServiceLocator.h"

class ServiceLocator;

class GameService 
{
private:

	ServiceLocator* service_locator{ nullptr };
	 sf::RenderWindow* game_window{ nullptr };

	void initialize(); // Handle game initialization
	void destroy(); // Destroys unneeded objects
	void initializeVariables();


public:

	GameService(); // Default Constructor 
	~GameService(); // Deconstructor

	void update(); // Updating game logic
	void ignite(); // initiates the game
	void render(); //Rendering the next frame
	bool isRunning(); //check if the game is currently running
	//sf::RenderWindow* GetGameWindow() const; // Getter for the game window instance

     
};