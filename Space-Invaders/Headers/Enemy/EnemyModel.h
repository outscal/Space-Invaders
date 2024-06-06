#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Entity\EntityConfig.h"

namespace Enemy
{
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;
	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_position;
		MovementDirection movement_direction;
		EnemyType enemy_type;
		EnemyState enemy_state;
		Entity::EntityType owner_type;

	public:
		EnemyModel(EnemyType type, Entity::EntityType owner_type);
		~EnemyModel();
		
		//const data related to movement and bounds
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 10.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 10.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);
		const float vertical_travel_distance = 100.f;
		const float enemy_movement_speed = 250.0f;
		
		void Initialize();
		
		//Getters and setters
		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);

		sf::Vector2f GetReferencePosition();
		void SetReferencePosition(sf::Vector2f position);

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection direction);

		EnemyType GetEnemyType();
		void SetEnemyType(EnemyType type);

		EnemyState GetEnemyState();
		void SetEnemyState(EnemyState state);
		Entity::EntityType GetEntityOwnerType();
	};
}