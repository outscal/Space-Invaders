#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Time\TimeService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\ZapperController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\SubzeroController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\Controllers\UFOController.h"



namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService() { std::srand(static_cast<unsigned>(std::time(nullptr))); }
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
			SpawnEnemy(Entity::EntityType::ENEMY);
			spawn_timer = 0.0f;
		}
	}
	EnemyController* EnemyService::SpawnEnemy(Entity::EntityType owner_type)
	{
		
		EnemyController* enemy_controller = CreateEnemy(GetRandomEnemyType(), owner_type);
		enemy_controller->Initialize();
		enemy_list.push_back(enemy_controller);
		return enemy_controller;
	}
	EnemyController* EnemyService::CreateEnemy(EnemyType enemy_type, Entity::EntityType owner_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			std::cout << "ZAPPER\n";
			return new ZapperController(Enemy::EnemyType::ZAPPER,owner_type);

			/*case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/

		case::Enemy::EnemyType::SUBZERO:
			std::cout << "SUBZERO\n";
			return new SubzeroController(Enemy::EnemyType::SUBZERO, owner_type);

			case::Enemy::EnemyType::UFO:
				std::cout << "UFO\n";
				return new UFOController(Enemy::EnemyType::UFO, owner_type);
		}
	}
	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = (std::rand() % 3)+1;  //random between 1-3.
		return static_cast<Enemy::EnemyType>(randomType); //cast int to EnemyType enum class
	}
	
	void EnemyService::Destroy()
	{
		//delete(enemy);
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]);
	}
	// Function to destroy an enemy controller object from the enemy_list vector.
	void EnemyService::DestroyEnemy(EnemyController* enemy_controller)
	{
		// Erase the enemy_controller object from the enemy_list vector:enemy_list.erase
		// std::remove rearranges the elements in the vector so that all elements 
		// that are equal to enemy_controller are moved to the end of the vector,
		// then it returns an iterator pointing to the start of the removed elements
		// The erase function then removes those elements from the vector.:enemy_list.begin() to enemy_list.end()
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());

		// Delete the enemy_controller object from memory to free up resources.
		delete(enemy_controller);
	}
}
