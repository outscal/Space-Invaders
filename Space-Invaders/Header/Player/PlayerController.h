#pragma once

#include "../../Header/GraphicService.h"
#include "../Player/PlayerView.h"
#include "../Player/PlayerModel.h"

class PlayerController
{
public:
	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPosition();

private:

	PlayerModel* player_model;
	PlayerView* player_view;

	void processInput();
	void moveLeft();
	void moveRight();



};

