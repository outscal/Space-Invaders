#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header//Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	EnemyService::EnemyService()
	{
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_delay;

	}

	void EnemyService::update()
	{
		updateTimer();
		processSpawnTimer();

		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->update();
		}
		//enemy_controller->update();
	}

	void EnemyService::render()
	{
		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->render();
		}
		//enemy_controller->render();
	}
	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = new EnemyController();
		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);
	}

	void EnemyService::updateTimer()
	{
		spawn_timer = spawn_timer + ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processSpawnTimer()
	{
		if (spawn_timer >= spawn_delay)
		{
			spawnEnemy();
			spawn_timer = 0;
		}
	}

	void EnemyService::Destroy()
	{
		for (int i = 0;i < enemy_list.size();i++)
		{
			delete(enemy_list[i]);
		}
		//delete(enemy_controller);
	}
}


