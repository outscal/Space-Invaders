#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class PlayerService
{   
private:
	int health=3;
	int playerScore = 0;
	float movementSpeed=0.1f;
	sf::Vector2f position = sf::Vector2f(200, 100);//set position in window

	const sf::String ship_Texture_path = "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/player_ship.png";

	sf::Texture ship_Texture;
	sf::Sprite ship_Sprite;

	sf::RenderWindow* game_window;

	void InitializePlayerSprite();
	void ProcessPlayerInput();

public:
	PlayerService();
	//PlayerService(int hp, int moveSpeed);
	~PlayerService();

	//Life Cycle methods
	void Initialize();
	void Update();
	void Render();
	
	//other methods
	float GetMovementSpeed();

	void MoveLeft();
	void MoveRight();
	
	//void TakeDamage();
	void Move(float offsetX);
	//void ShootBullets();

	sf::Vector2f GetPosition();


};