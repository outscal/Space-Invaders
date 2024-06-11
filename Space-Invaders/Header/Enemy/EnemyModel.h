#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel
	{
	public:
		EnemyModel();
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f set_position);

		sf::Vector2f getRefPosition();
		void setRefPosition(sf::Vector2f set_position);

	private:
		sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f current_position;

		
	};
}