#pragma once
//To handle all the logic of the player
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Player/PlayerModel.h"
#include "../../HeaderFiles/Player/PlayerView.h"
class PlayerModel;
class PlayerView;
enum class PlayerState;


namespace Player 
{
	
	class PlayerController {

	private:
		//float variable to store the current pos of the player


		//pointers to player view and model
		PlayerView* playerView;
		PlayerModel* playerModel;


		void ProcessPlayerInput();
		void moveRight();
		void moveLeft();

	public:

		//Constructors and deconstructors
		PlayerController();
		~PlayerController();

		//Lifecycle methpds
		void update();
		void initialize();
		void render();

		//Setters and getters
		sf::Vector2f getPlayerPosition();



	};
}