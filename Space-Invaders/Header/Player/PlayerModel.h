#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
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
		const sf::Vector2f left_window = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_window = sf::Vector2f(1800.f, 950.f);

		PlayerState player_state;
		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

		void initialize();
		void reset();

		PlayerState getPlayerAlive();
		void setPlayerAlive(PlayerState state);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 5.f);

	private:
		const sf::Vector2f initial_position = sf::Vector2f(950.f, 950.f);


		sf::Vector2f current_position;





	};

}
