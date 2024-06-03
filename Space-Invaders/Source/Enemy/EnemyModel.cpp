#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type) 
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize()
	{	
		//init with RIGHT
		enemy_state = EnemyState::PATROLLING;
		movement_direction = MovementDirection::RIGHT;
		enemy_position = reference_position;
	}
	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemy_position;
	}
	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}
	sf::Vector2f EnemyModel::GetReferencePosition()
	{
		return reference_position;
	}
	void EnemyModel::SetReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}
	MovementDirection EnemyModel::GetMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::SetMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	EnemyState EnemyModel::GetEnemyState()
	{
		return enemy_state;
	}
	void EnemyModel::SetEnemyState(EnemyState state)
	{
		enemy_state = state;
	}
	EnemyType EnemyModel::GetEnemyType()
	{
		return enemy_type;
	}
	void EnemyModel::SetEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

}