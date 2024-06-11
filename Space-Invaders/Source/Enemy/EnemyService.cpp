#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header//Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	EnemyService::EnemyService()
	{
		enemy_controller = nullptr;
	
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
	}

	void EnemyService::render()
	{
		enemy_controller->render();
	}
	EnemyController* EnemyService::spawnEnemy()
	{
		enemy_controller = new EnemyController();
		enemy_controller->initialize();
		return enemy_controller;
	}
	void EnemyService::Destroy()
	{
		delete(enemy_controller);
	}
}


