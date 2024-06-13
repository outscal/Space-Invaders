#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	class EnemyService
	{
	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();
		


	private:
		const float spawn_delay = 3.f;
		float spawn_timer;
		//EnemyController* enemy_controller;
		std::vector<EnemyController*> enemy_list;
		void updateTimer();
		void processSpawnTimer();
		void Destroy();
	};

}

