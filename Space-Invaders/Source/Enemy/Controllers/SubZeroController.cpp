#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\SubZeroController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;
	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type):EnemyController(type){}
		

		SubzeroController::~SubzeroController() { }

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
		void SubzeroController::FireBullet()
		{
			// we spawn the bullet and pass the needed parameters
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
				enemy_model->GetEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}
		void SubzeroController::Initialize()
		{
			EnemyController::Initialize();
			enemy_model->SetMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire; 
		}
	}
}
