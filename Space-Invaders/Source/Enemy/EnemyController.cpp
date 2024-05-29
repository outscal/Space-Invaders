#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"


namespace Enemy
{
	using namespace Global;
	
	EnemyController::EnemyController(EnemyType type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}
	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}
	sf::Vector2f EnemyController::GetRandomInitialPosition()
	{
		// Calculate the distance between the leftmost and rightmost positions of the enemy.
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		// Calculate the x position by adding the x offset distance to the leftmost position.
		float x_position = enemy_model->left_most_position.x + x_offset_distance;

		// The y position remains the same.
		float y_position = enemy_model->left_most_position.y;

		// Return the calculated position as a 2D vector.
		return sf::Vector2f(x_position, y_position);
	}
	void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		// Destroy the enemy if it goes out of bounds.
		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
			std::cout << "Out of bounds:Destroyed";
		}
	}
	//Lifecycle Methods
	void EnemyController::Initialize()
	{
		enemy_model->Initialize();
		enemy_model->SetEnemyPosition(GetRandomInitialPosition());
		enemy_view->Initialize(this);
	}
	void EnemyController::Update()
	{	
		Move();
		enemy_view->Update();
		HandleOutOfBounds();
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
	EnemyType EnemyController::GetEnemyType()
	{
		return enemy_model->GetEnemyType();
	}
}