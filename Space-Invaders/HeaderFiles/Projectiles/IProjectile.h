#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include "../../HeaderFiles/Bullet/BulletConfig.h"

namespace Projectile
{

	enum class MovememtDirection;
	class IProjectile
	{
	public:

		virtual void initialize(sf::Vector2f position, Bullet::MovementDirection direction) = 0;

		virtual void update() = 0;
		virtual void render() = 0;

		virtual sf::Vector2f getProjectilePosition() = 0;
		virtual void updateProjectilePosition() = 0;
		virtual ~IProjectile();
	};

}