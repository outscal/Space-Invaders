#pragma once
<<<<<<< Updated upstream
#include "../Header/ServiceLocator.h"

class GameService
{
private:
	ServiceLocator* serviceLocator;
	sf::RenderWindow* game_window;

	void initialize(); // Handles Intialize the game		
	void destroy();	// Handles Clean up the memory


public:
	GameService();  //Constructor
	~GameService();	    //Destructor

	void ignite();	//Intialize the game
	void update();	//update the game logic and game state
	void render();		//render game in each frame
	bool isRunning();  //check if game is running or not
	void initializeVariables();

	
};
=======
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

>>>>>>> Stashed changes
