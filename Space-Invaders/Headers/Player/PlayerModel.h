#pragma once
#include <SFML/Graphics.hpp>
namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
		//Add more states when necessary
	};
	class PlayerModel
	{
	private:
		const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);

		sf::Vector2f player_position;
		PlayerState player_state;
		int player_score;
	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);
		const float player_movement_speed = 350.f;

		PlayerModel();
		~PlayerModel();

		//LifeCycle Methods
		void Initialize();
		void Reset();

		//Getters and setters
		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);
		int GetPlayerScore();
		void SetPlayerScore(int score);

		PlayerState GetPlayerState();
		void SetPLayerState(PlayerState state);
	};
}
