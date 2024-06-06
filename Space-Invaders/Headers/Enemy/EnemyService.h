#pragma once
#include <vector>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Entity\EntityConfig.h"

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
		EnemyController* CreateEnemy(EnemyType enemy_type, Entity::EntityType owner_type);
		void Destroy();

	public:
		EnemyService();
		virtual ~EnemyService();
		
		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy(Entity::EntityType owner_type);
		void DestroyEnemy(EnemyController* enemy_controller);
	};

}
