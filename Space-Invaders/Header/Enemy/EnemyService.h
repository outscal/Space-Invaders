#pragma once


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

		EnemyController* spawnEnemy();


	private:
		EnemyController* enemy_controller;
		void Destroy();
	};

}

