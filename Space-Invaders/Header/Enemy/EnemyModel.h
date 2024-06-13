#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN
	};
	class EnemyModel
	{
	public:
		EnemyModel();
		~EnemyModel();

		float move_speed = 250.f;
		const sf::Vector2f left_window = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_window = sf::Vector2f(1800.f, 950.f);
		const float down_distance = 100.f;

		void initialize();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f set_position);

		sf::Vector2f getRefPosition();
		void setRefPosition(sf::Vector2f set_position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);



	private:
		sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f current_position;

		MovementDirection movement_direction;

	

		
	};
}