#pragma once
//#include "../../HeaderFiles/Enemy/EnemyController.h"
#include <vector>


namespace Enemy {

	class EnemyController;
	enum class EnemyType;

	class EnemyService {

	private:
		std::vector<EnemyController*> enemyList;
		void destroy();

		const float enemySpawnDelay = 2.0f;
		float spawnTimer;
		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType createenemy);
	public:

		EnemyService();
		virtual ~EnemyService();

		
		void initialize();
		void update();
		void render();
		
		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController * enemycontroller);

		
		
		
	};
}