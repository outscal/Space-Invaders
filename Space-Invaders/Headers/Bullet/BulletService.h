#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Projectile\IProjectile.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bullet_list;
		BulletController* CreateBullet(BulletType bullet_type);
		void Destroy();
	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction);
		void DestroyBullet(BulletController* bullet_controller);
	};
}