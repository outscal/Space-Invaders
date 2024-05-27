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
	void EnemyController::Initialize()
	{
		enemy_model->Initialize();
		enemy_view->Initialize(this);
	}
	void EnemyController::Update()
	{
		enemy_view->Update();
	}
	void EnemyController::Render()
	{
		enemy_view->Render();
	}
	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemy_model->GetEnemyPosition();
	}
}