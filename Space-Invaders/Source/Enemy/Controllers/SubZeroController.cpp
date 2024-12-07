#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Controller;
	using namespace Global;
	namespace Controller
	{
		Enemy::SubZeroController::SubZeroController(EnemyType type):EnemyController(type)
		{

		}

		Enemy::SubZeroController::~SubZeroController()
		{
		}

		void Enemy::SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
		}

		void Enemy::SubZeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::DOWN:
				moveDown();
			default:
				break;
			}
		}

		void Enemy::SubZeroController::moveDown()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.y += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(current_position);
		}
	}


}
