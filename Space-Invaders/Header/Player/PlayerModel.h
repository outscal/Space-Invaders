#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerState //Our Enum
{
	ALIVE,
	DEAD,
	//Add more later
};

class PlayerModel
{
private:

	const sf::Vector2f initial_player_position = sf::Vector2f(500.f, 500.f); // new variable
	sf::Vector2f player_position; //new variable
	PlayerState player_state; //Declaration
	int player_score;

public:
	const sf::Vector2f left_most_position = sf::Vector2f(50.f, 0.f);
	const sf::Vector2f right_most_position = sf::Vector2f(700.f, 0.f);

	const float player_movement_speed = 200.0f;

	PlayerModel();
	~PlayerModel();

	void initialize();
	void reset(); //new method

	//getters and setters
	sf::Vector2f getPlayerPosition();
	void setPlayerPositions(sf::Vector2f position);

	int getPlayerScore();
	void setPlayerScore(int score);

	//new getter and setter for states
	PlayerState getPlayerState();
	void setPlayerState(PlayerState state);

};