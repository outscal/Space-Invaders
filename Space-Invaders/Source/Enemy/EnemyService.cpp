#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Time\TimeService.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;

	EnemyService::EnemyService() {  }
	EnemyService::~EnemyService() { Destroy(); }

	void EnemyService::Initialize()
	{	
		spawn_timer = spawn_interval;
	}
	void EnemyService::Update()
	{
		UpdateSpawnTimer();
		ProcessEnemySpawn();
		for (int i = 0; i < enemy_list.size();i++)enemy_list[i]->Update();
	}
	void EnemyService::Render()
	{
		for (int i = 0; i < enemy_list.size();i++)enemy_list[i]->Render();
	}
	void EnemyService::UpdateSpawnTimer()
	{
		spawn_timer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}
	void EnemyService::ProcessEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			SpawnEnemy();
			spawn_timer = 0.0f;
		}
	}
	void EnemyService::SpawnEnemy()
	{
		/*enemy = new EnemyController();
		enemy->Initialize();
		return enemy;*/
		EnemyController* enemy_controller = new EnemyController();
		enemy_controller->Initialize();
		enemy_list.push_back(enemy_controller);
	}
	void EnemyService::Destroy()
	{
		//delete(enemy);
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]);
	}
}
