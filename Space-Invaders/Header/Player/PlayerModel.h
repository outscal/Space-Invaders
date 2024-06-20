#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{


	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class PlayerModel
	{
	private:
		const sf::Vector2f initial_player_position = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f player_position;
		PlayerState player_state;
		int player_score;

	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

		const float movement_speed = 350.0f;
		PlayerModel();
		~PlayerModel();

		void initialize();
		void reset();

		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

		int getPlayerScore();
		void setPlayerScore(int score);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);


	};
}
