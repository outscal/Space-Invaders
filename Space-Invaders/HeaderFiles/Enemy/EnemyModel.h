#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy 
{
	enum class EnemyState;
	enum class EnemyType;
	enum class MovementDirection;

	class EnemyModel
	{
	private:

		sf::Vector2f referencePosition = (sf::Vector2f(50.0f, 50.f));
		sf::Vector2f enemyPosition;

		EnemyState enemyState;
		EnemyType enemyType;
		MovementDirection movementDirection;
	

	

	public:
		
		const float enemyMovementSpeed = 250.0f;
		const float enemyVerticalDistance = 100.0f;

		const sf::Vector2f leftScreenSide = sf::Vector2f(50.0f, 50.0f);
		const sf::Vector2f rightScreenSide = sf::Vector2f(1800.0f, 50.0f);
		const sf::Vector2f bottomScreenSide = sf::Vector2f(0.0f, 100.0f);
	
		EnemyModel();
		EnemyModel(EnemyType setType);
		~EnemyModel();
	

		//Lifecycle

		void initialize();
		//void update();
		//void render();

		//setters and getters
		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		MovementDirection getMovementDirection();

		void setMovementDirection(MovementDirection direction);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType setType);
	};

}
