#pragma once
#include <vector>
namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		const float spawn_interval = 3.f;
		std::vector<EnemyController*>enemy_list;
		float spawn_timer;
		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		void Destroy();
		//EnemyController* enemy;

	public:
		EnemyService();
		virtual ~EnemyService();
		
		void Initialize();
		void Update();
		void Render();

		void SpawnEnemy();
	};

}
