#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyService::EnemyService() { enemy = nullptr; }
	EnemyService::~EnemyService() { Destroy(); }

	void EnemyService::Initialize()
	{
		SpawnEnemy();
	}
	void EnemyService::Update()
	{

	}
	void EnemyService::Render()
	{
		enemy->Render();
	}
	EnemyController* EnemyService::SpawnEnemy()
	{
		enemy = new EnemyController();
		enemy->Initialize();
		return enemy;
	}
	void EnemyService::Destroy()
	{
		delete(enemy);
	}
}
