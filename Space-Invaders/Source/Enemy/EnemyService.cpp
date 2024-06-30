#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Enemy/Controllers/SubZeroController.h"
#include"../../Header/Enemy/Controllers/ZapperController.h"
namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	

	EnemyService::EnemyService() 
	{ 
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval; // for the first spawn
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->update();
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); // increase timer
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy(); //spawn 
			spawn_timer = 0.0f; // reset
		}
	}
	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
{
    switch (enemy_type)
    {
    case Enemy::EnemyType::ZAPPER:
        return new ZapperController(Enemy::EnemyType::ZAPPER);

    case Enemy::EnemyType::SUBZER:
        return new SubzeroController(Enemy::EnemyType::SUBZER);

    default:
        return nullptr; // or handle error appropriately
    }
} 
	EnemyController* EnemyService::spawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());

		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}
	//void EnemyService::spawnEnemy()
	//{
	//	EnemyController* enemy_controller = new EnemyController(); // create
	//	enemy_controller->initialize(); // init as soon as created

	//	enemy_list.push_back(enemy_controller); //add to list
	//}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]); //delete all enemies
	}
}