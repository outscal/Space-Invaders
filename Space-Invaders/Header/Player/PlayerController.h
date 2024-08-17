#pragma once
#include<SFML/Graphics.hpp>
//#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\PlayerModel.h"
//#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\PlayerView.h"

enum class PlayerState;
class PlayerView;
class PlayerModel;
class PlayerController
{
private:
	PlayerModel* playerModel;
	PlayerView* playerView;

	void processPlayerInput();


	void moveLeft();
	void moveRight();

public:
	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPlayerPosition();
	

};