#include "../../HeaderFiles/Enemy/Controllers/ThunderSnake.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	namespace Controllers
	{
		ThunderSnake::ThunderSnake(EnemyType setType) : EnemyController(setType)
		{

		}

		ThunderSnake::~ThunderSnake()
		{

		}

		void ThunderSnake::moveRightDiagonal()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += horizontalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
			currentPosition.y +=  verticalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x >= enemyModel->rightScreenSide.x ) 
			{
				enemyModel->setMovementDirection(MovementDirection::LEFT);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}
		void ThunderSnake::moveLeftDiagonal()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= horizontalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
			currentPosition.y += verticalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x <= enemyModel->leftScreenSide.x )
			{
				enemyModel->setMovementDirection(MovementDirection::RIGHT);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}
		void ThunderSnake::initialize()
	    {
			EnemyController::initialize();
		}

		void ThunderSnake::move()
		{
			switch (enemyModel->getMovementDirection())
			{
			case Enemy::MovementDirection::RIGHT:
				moveRightDiagonal();
				break;
			case Enemy::MovementDirection::LEFT:
				moveLeftDiagonal();
				break;
			}
		}


	}
}
