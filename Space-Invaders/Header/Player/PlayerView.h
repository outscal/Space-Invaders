#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"


class PlayerView
{
public:
	PlayerView();
	~PlayerView();

	void initialize(PlayerController* player_controller);
	void update();
	void render();

private:

	const sf::String player_texture_path = "assets/textures/player_ship.png";
	sf::Texture player_texture;
	sf::Sprite player_sprite;
	int sprite_height = 60;
	int sprite_width = 60;

	sf::RenderWindow* game_window;
	PlayerController* player_controller;

	void initializePlayerSprite();
	void scaleSprite();
};
