#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerView.h"

class PlayerController
{
private:
	PlayerView* player_view;
	PlayerModel* player_model;
void ProcessPlayerInput();
void MoveRight();
void MoveLeft();
public:
	PlayerController();
	~PlayerController();
	void Initialize();
	void Update();
	void Render();
	sf::Vector2f GetPlayerPosition();
};