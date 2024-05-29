#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\SubZeroController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type):EnemyController(type){}
		

		SubzeroController::~SubzeroController() { }

		void SubzeroController::Initialize()
		{
			EnemyController::Initialize();
			enemy_model->SetMovementDirection(MovementDirection::DOWN);
			
		}

		void SubzeroController::Move()
		{
			switch (enemy_model->GetMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void SubzeroController::MoveDown()
		{
			sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			enemy_model->SetEnemyPosition(currentPosition);
		}
	}
}
