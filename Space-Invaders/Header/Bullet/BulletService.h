#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	class BulletController;
	enum class ButtonType;
	enum class MovementDirection;
	class BulletService
	{
	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spawnBullet(sf::Vector2f psoition, MovementDirection direction, BulletType type);
		void destroyBullet(BulletController* controller);

	private:
		std::vector<IProjectile*> bullet_list;
		BulletController* createBullet(BulletType type);
		void destroy();
	};
}


