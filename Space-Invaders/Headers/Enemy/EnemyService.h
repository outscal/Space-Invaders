#pragma once
#include <vector>
namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		const float spawn_interval = 2.f;
		std::vector<EnemyController*>enemy_list;
		float spawn_timer;
		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType();
		EnemyController* CreateEnemy(EnemyType enemy_type);
		void Destroy();

	public:
		EnemyService();
		virtual ~EnemyService();
		
		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemy_controller);
	};

}
