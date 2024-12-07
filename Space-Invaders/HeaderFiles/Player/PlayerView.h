#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Player/PlayerController.h"

namespace Player 
{
	class PlayerController;

	//To render all the player images onto the screen

	class PlayerView {

	private:
		const sf::String player_texture_path = "assets/textures/player_ship.png";
		const float spriteHeight = 60.0f;
		const float spriteWidth = 60.0f;

		sf::Texture playerTexture;
		sf::Sprite playerSprite;
		sf::RenderWindow* gameWindow;
		void initializePlayerSprite();
		void scalePlayerSprite();

		PlayerController* playerController;

	public:
		PlayerView();
		~PlayerView();

		//LIfecycle methods
		void initialize();
		void render();
		void update();

		void initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view later.
	};
}
	


