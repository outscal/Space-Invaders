#pragma once
#include<SFML/Graphics.hpp>
//#include "../../Header/Player/PlayerController.h"

class PlayerController;

class PlayerView {
private:
	const sf::String player_texture_path = "assets/textures/player_ship.png";
	const float player_sprite_width = 60.f;
	const float player_sprite_height = 60.f;
	PlayerController* player_controller;

	sf::RenderWindow* game_window;

	sf::Texture player_texture;
	sf::Sprite player_sprite;

	
	void initializePlayerSprite();
	void scaleSprite();

public:
	PlayerView();
	~PlayerView();

	void Initialise(PlayerController* controller);
	void Update();
	void Render();


};