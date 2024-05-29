#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\ZapperController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"
namespace Enemy
{
	using namespace Global;
	namespace Controller
	{
		ZapperController::ZapperController(EnemyType type):EnemyController(type) {}

		ZapperController::~ZapperController() { }

		void ZapperController::Initialize()
		{
			EnemyController::Initialize();;
		}

		void ZapperController::Move()
		{
			switch (enemy_model->GetMovementDirection())
			{
				// If the movement direction is LEFT
			case::Enemy::MovementDirection::LEFT:
				MoveLeft();
				break;

				// If the movement direction is RIGHT
			case::Enemy::MovementDirection::RIGHT:
				MoveRight();
				break;

				// If the movement direction is DOWN
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void ZapperController::MoveLeft()
		{	
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
			// Update the position to move left
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			// Check if the enemy reached the leftmost position
			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->SetMovementDirection(MovementDirection::DOWN);
				enemy_model->SetReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->SetEnemyPosition(currentPosition);
			}
		}

		void ZapperController::MoveRight()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();

			// Update the position to move right
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			// Check if the enemy reached the rightmost position
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				// Set movement direction to DOWN and update reference position
				enemy_model->SetMovementDirection(MovementDirection::DOWN);
				enemy_model->SetReferencePosition(currentPosition);
			}
			else
			{
				// Update the enemy position
				enemy_model->SetEnemyPosition(currentPosition);
			}
		}

		void ZapperController::MoveDown()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();

			// Update the position to move down
			currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			// Check if the enemy reached the reference position plus vertical travel distance
			if (currentPosition.y >= enemy_model->GetReferencePosition().y + vertical_travel_distance)
			{
				// Check if the enemy reference position is on the left side
				if (enemy_model->GetReferencePosition().x <= enemy_model->left_most_position.x)
				{
					// Set movement direction to RIGHT
					enemy_model->SetMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					// Set movement direction to LEFT
					enemy_model->SetMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				// Update the enemy position
				enemy_model->SetEnemyPosition(currentPosition);
			}
		}
	}
}