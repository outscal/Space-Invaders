#pragma once
#include "../../Header//Bullet/BulletConfig.h"
#include <SFML/System/Vector2.hpp>

namespace Bullet
{
	class IProjectile
	{
		enum class MovementDirection;
	public:

		virtual void initialize(sf::Vector2f position,Bullet::MovementDirection dirction) = 0;
		virtual void updateProjectile() = 0;
		virtual sf::Vector2f getProjectilePosition() = 0;

		virtual void update() = 0;
		virtual void render() = 0;

		virtual ~IProjectile() {};

	private:

	};

}

