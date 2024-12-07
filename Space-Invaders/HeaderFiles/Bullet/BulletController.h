#pragma once

#include "../../HeaderFiles/Bullet/BulletConfig.h"
#include "../../HeaderFiles/Projectiles/IProjectile.h"

namespace Bullet
{

	enum class BulletType;
	class BulletModel;
	class BulletView;

	class BulletController : public Projectile::IProjectile
	{
	protected:

		BulletModel* bulletModel;
		BulletView * bulletView;

		void updateProjectilePosition() override;

		void moveUp();
		void moveDown();

		void handleOutOfBounds();

	public:

		BulletController(BulletType type);
		virtual ~BulletController() override;

		void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void update() override;
		void render() override ;

		sf::Vector2f getProjectilePosition();
		BulletType getBulletType();



	};
}