#include "../../HeaderFiles/Enemy/Controllers/Zapper.h"

#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	namespace Controllers
	{
		Zapper::Zapper(EnemyType setType) :EnemyController(setType) {

		}

		Zapper::~Zapper()
		{

		}

		void Zapper::initialize()
		{
			EnemyController::initialize();
			//enemyModel->setMovementDirection(MovementDirection::RIGHT);
		}

		void Zapper::move()
		{

			switch (enemyModel->getMovementDirection())
			{
			case Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			case Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			case Enemy::MovementDirection::LEFT:
				moveLeft();
				break;
			}
		}

		void Zapper::moveDown()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.y += enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.y >= enemyModel->getReferencePosition().y + verticalTravelDistance)
			{
				if (enemyModel->getReferencePosition().x <= enemyModel->leftScreenSide.x)
				{
					enemyModel->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemyModel->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}

		void Zapper::moveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x <= enemyModel->leftScreenSide.x)
			{
				enemyModel->setMovementDirection(MovementDirection::DOWN);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}

		void Zapper::moveRight()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x >= enemyModel->rightScreenSide.x)
			{
				enemyModel->setMovementDirection(MovementDirection::DOWN);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
	}
}