#include "../../Header/Enemy/EnemyModel.h"


namespace Enemy
{
	Enemy::EnemyModel::EnemyModel()
	{
		
	}

	Enemy::EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::initialize()
	{
		current_position = initial_position;
	}

	sf::Vector2f EnemyModel::getRefPosition()
	{
		return initial_position;;
	}

	void EnemyModel::setRefPosition(sf::Vector2f set_position)
	{
		initial_position = set_position;
	}

	sf::Vector2f Enemy::EnemyModel::getEnemyPosition()
	{
		return current_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f set_position)
	{
		current_position = set_position;
	}
}

