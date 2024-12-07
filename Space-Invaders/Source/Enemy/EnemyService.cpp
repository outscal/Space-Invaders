#include "../../HeaderFiles/Enemy/EnemyService.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Time/TimeService.h"
#include "../../HeaderFiles/Enemy/Controllers/SubZero.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include "../../HeaderFiles/Enemy/Controllers/Zapper.h"
#include "../../HeaderFiles/Enemy/Controllers/ThunderSnake.h"
#include <SFML/Graphics.hpp>
namespace Enemy {
	using namespace Global;
	using namespace Time;
	using namespace Controllers;


	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() {
		destroy();
	}

	void EnemyService::initialize() {
		spawnTimer = enemySpawnDelay;
		spawnEnemy();
	}

	void EnemyService::update() {
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->update();
		}
	}

	void EnemyService::render() {
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->render();
		}
	}

	void EnemyService::destroy() {
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete enemyList[i];
		}
	}

    EnemyController * EnemyService::spawnEnemy() {
		EnemyController* enemycontroller = createEnemy(getRandomEnemyType());
	
		enemycontroller->initialize();

		enemyList.push_back(enemycontroller);
		return enemycontroller;
	
	}
	void EnemyService::updateSpawnTimer() {
		spawnTimer += ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
	}

	// Inside the method to process enemy spawn, we will spawn an enemy if the spawn timer is more than the the interval. Then  we will set time timer back to 0.
	void EnemyService::processEnemySpawn() 
	{
		if (spawnTimer >= enemySpawnDelay)
		{
			spawnEnemy();
			spawnTimer = 0.0f;
		}
	}

	EnemyController* EnemyService::createEnemy(EnemyType createenemy)
	{
		switch (createenemy)
		{
		case Enemy::EnemyType::ZAPPER:
			//EnemyController* createenemy = new Zapper();
			return new Zapper(Enemy::EnemyType::ZAPPER);

		case Enemy::EnemyType::SUBZERO:
			return new SubZero(Enemy::EnemyType::SUBZERO);
			
		case Enemy::EnemyType::THUNDERSNAKE:
			return new ThunderSnake(Enemy::EnemyType::THUNDERSNAKE);

			//case Enemy::EnemyType::UFO:
		//return new UFO(Enemy::EnemyType::UFO);
			 
		
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 3;
		return static_cast<Enemy::EnemyType> (randomType);
	}

	void EnemyService::destroyEnemy(EnemyController* enemycontroller)
	{
		// Erase the enemy_controller object from the enemy_list vector.
        // std::remove rearranges the elements in the vector so that all elements 
        // that are equal to enemy_controller are moved to the end of the vector,
        // then it returns an iterator pointing to the start of the removed elements.
        // The erase function then removes those elements from the vector.
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemycontroller),enemyList.end());

		delete (enemycontroller);
	}

}