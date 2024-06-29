#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>



namespace Enemy
{

	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

		SubzeroController::~SubzeroController() { }

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire;
		}

		void SubzeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
			std::cout << "shot";
		}

		void SubzeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}
	}
}