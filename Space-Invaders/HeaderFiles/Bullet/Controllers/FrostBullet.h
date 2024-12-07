#pragma once
#include "../../HeaderFiles/Bullet/BulletController.h"

namespace Bullet
{
	namespace BulletControllers
	{
		class FrostBullet : public BulletController
		{
		private:

			const float frostbulletMovementSpeed = 500.0f;

		public:

			FrostBullet(BulletType type);

			~FrostBullet();

			void initialize(sf::Vector2f position, MovementDirection direction);
		};
	}
}
