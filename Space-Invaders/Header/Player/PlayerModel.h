#pragma once
#include<SFML/Graphics.hpp>
enum class PlayerState {
	ALIVE,
	DEAD,
};
class PlayerModel
{
private:
	const sf::Vector2f initialPlayerPosition = sf::Vector2f(500.0f, 500.0f); //new Var
	sf::Vector2f playerPosition;
	bool playerAlive;
	int playerScore = 0;
	PlayerState playerState;
	
	

public:
	

	const sf::Vector2f left_most_position = sf::Vector2f(50.f, 0.f);
	const sf::Vector2f right_most_position = sf::Vector2f(700.f, 0.f);
	const float playerMovementSpeed = 200.0f;
	PlayerModel();
	~PlayerModel();

	void Initialize();
	void Reset();


	//getters and setters
	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(sf::Vector2f position);


	int getPlayerScore();
	void setPlayerScore(int score);
	PlayerState getPlayerState();
	void setPlayerState(PlayerState state);

	
};