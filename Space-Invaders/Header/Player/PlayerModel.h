#pragma once
#include <SFML/Graphics.hpp>


enum class PlayerState {
	ALIVE,
	DEAD
};
class PlayerModel
{
public:
	PlayerModel();
	~PlayerModel();

	const float player_movement_speed = 200.0f;
	int player_score = 0;
	const sf::Vector2f left_window = sf::Vector2f(50.f, 0.f);
	const sf::Vector2f right_window = sf::Vector2f(700.f, 0.f);

	PlayerState player_state;
	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(sf::Vector2f position);

	void initialize();
	void reset();

	PlayerState getPlayerAlive();
	void setPlayerAlive(PlayerState state);
private:
	const sf::Vector2f initial_positon = sf::Vector2f(500.f,500.f);


	sf::Vector2f current_position;
	




};
