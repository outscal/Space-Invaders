#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class  LaserBulletController :public BulletController
		{
		public:
			LaserBulletController(BulletType type);
			~LaserBulletController();

		private:
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}

}


