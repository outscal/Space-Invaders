#pragma once
#include "../../Header/Bullet/BulletController.h"


namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController:public BulletController
		{
		public:
			FrostBulletController(BulletType type);
			~FrostBulletController();

		private:
			const float movement_speed = 500.f;
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}
}


