#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}
	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}
	//Enemy movement state handler
	void EnemyController::Move()
	{
		switch (enemy_model->GetMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			MoveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			MoveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			MoveDown();
			break;
		}
	}
	//Enemy Movement
	void EnemyController::MoveRight()
	{
		sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
		currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		if (currentPosition.x >= enemy_model->right_most_position.x)
		{
			enemy_model->SetMovementDirection(MovementDirection::DOWN); // move
			enemy_model->SetReferencePosition(currentPosition);// set ref pos
		}
		else enemy_model->SetEnemyPosition(currentPosition);
	}
	void EnemyController::MoveLeft()
	{
		sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
		currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		if (currentPosition.x >= enemy_model->left_most_position.x)
		{	//if reached the left most pos
			//start moving down
			//set ref pos for the downwards movement
			enemy_model->SetMovementDirection(MovementDirection::DOWN); // move
			enemy_model->SetReferencePosition(currentPosition);// set ref pos
		}
		else enemy_model->SetEnemyPosition(currentPosition);
	}
	void EnemyController::MoveDown()
	{
		sf::Vector2f currentPosition = enemy_model->GetEnemyPosition();
		currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.y >= enemy_model->GetReferencePosition().y + enemy_model->vertical_travel_distance)
		{
			if (enemy_model->GetReferencePosition().x <= enemy_model->left_most_position.x)
				enemy_model->SetMovementDirection(MovementDirection::RIGHT);
			else enemy_model->SetMovementDirection(MovementDirection::LEFT);
		}
		else enemy_model->SetEnemyPosition(currentPosition);
	}
	//Lifecycle Methods
	void EnemyController::Initialize()
	{
		enemy_model->Initialize();
		enemy_view->Initialize(this);
	}
	void EnemyController::Update()
	{	
		Move();
		enemy_view->Update();
	}
	void EnemyController::Render()
	{
		enemy_view->Render();
	}
	//Getters and Setters
	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemy_model->GetEnemyPosition();
	}
}