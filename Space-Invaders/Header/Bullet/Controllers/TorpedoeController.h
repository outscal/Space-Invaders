#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class TorpedoeController:public BulletController
		{
		public:
			TorpedoeController(BulletType type);
			~TorpedoeController();

		private:
			const float movement_speed = 200.f;
			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;

		};
	}
}

