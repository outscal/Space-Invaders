#include "../../HeaderFiles/Enemy/Controllers/SubZero.h"
//#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;

	namespace Controllers
	{
		SubZero::SubZero(EnemyType setType) : EnemyController(setType)
		{
		}
		void SubZero::initialize() 
		{
			EnemyController::initialize();
			enemyModel->setMovementDirection(MovementDirection::DOWN);

		}

		
		SubZero::~SubZero()
		{
			
		}

		void SubZero::move()
		{
			switch (MovementDirection::DOWN)
			{
			case Enemy::MovementDirection::DOWN:
				moveDown();
				break;
		
			}
		}

		void SubZero::moveDown()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();

			currentPosition.y += movementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			enemyModel->setEnemyPosition(currentPosition);

		}

	}
}