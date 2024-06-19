#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Bullet/BulletConfig.h"


namespace Bullet
{
	class BulletView;
	class BulletModel;
	enum class BulletType;

	class  BulletController : public IProjectile::IProjectile
	{
		
	protected:
		BulletModel* bullet_model;
		BulletView* bullet_view;

		void  updateProjectilePosition() override;
		void moveUp();
		void moveDown();
		void handleOutOfBounds();

	public:
		BulletController(BulletType type);
		virtual ~BulletController() override;

		void initialize(sf::Vector2f position, Bullet::MovementDirection dirction) override;
		void update() override;
		void render() override;

		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
	};

}
