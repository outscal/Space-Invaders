#pragma once

#include <SFML/Graphics.hpp>
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Global\ServiceLocator.h"
class GameService
{
private:
	ServiceLocator* serviceLocator;
	sf::RenderWindow* gameWindow;

	

	void Initialize(); //initialize the game
	void InitializeVariables();
	void Destroy();  //cleanup of resources


public:
	GameService(); //construtor for initializing game service object
	~GameService(); //destrutor for cleaning up the resources

 	void Ignite();  //Start the game
	void Update();   //Updates Game logic and states
	void Render();  //Render things on Screen
	bool IsGameRunning(); //checks if game is running




};