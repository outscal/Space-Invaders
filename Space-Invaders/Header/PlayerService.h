#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/EventService.h"

class PlayerService
{
public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	void move(float offsetX);
	int getMoveSpeed();
	sf::Vector2f getposition();


private:
	 int player_score = 3;
	 int health = 10;
	 int movespeed = 5;
	 sf::Vector2f player_position =  sf::Vector2f(200,100);

	const sf::String player_texture_path = "assets/textures/player_ship.png";

	 sf::Texture player_texure;
	 sf::Sprite player_sprite;

	 void initializePlayerSprite();
	 void processPlayerInput();

	 sf::RenderWindow* game_window;
	 EventService* game_event;
};
