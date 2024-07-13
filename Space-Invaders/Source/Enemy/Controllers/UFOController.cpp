#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\UFOController.h"


namespace Enemy
{
    namespace Controller
    {
        using namespace Global;

        UFOController::UFOController(EnemyType type, Entity::EntityType owner_type) :EnemyController(type, owner_type) {}
        UFOController::~UFOController() {}

        void UFOController::Initialize()
        {
            EnemyController::Initialize();
            enemy_model->SetMovementDirection(MovementDirection::RIGHT);
        }
        void UFOController::Move() 
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
            }
        }
        void UFOController::MoveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
            // Update the position to move left
            currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->SetMovementDirection(MovementDirection::RIGHT);
                enemy_model->SetReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->SetEnemyPosition(currentPosition);
            }
        }
        void UFOController::MoveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();

            // Update the position to move right
            currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->SetMovementDirection(MovementDirection::LEFT);
                enemy_model->SetReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->SetEnemyPosition(currentPosition);
            }
        }
        Powerup::PowerupType UFOController::GetRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            // Added '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, need to add 1 to make it 4 

            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
            return static_cast<Powerup::PowerupType>(random_value);
        }
        void UFOController::FireBullet(){}
    }
}