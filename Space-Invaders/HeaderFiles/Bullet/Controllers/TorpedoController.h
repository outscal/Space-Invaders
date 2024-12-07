#pragma once
#include "../../HeaderFiles/Bullet/BulletController.h"

namespace Bullet
{
	namespace BulletControllers
	{
		class Torpedo : public BulletController
		{
		private:

			const float torpedoMovementSpeed = 200.0f;

		public:

			void initialize(sf::Vector2f position, MovementDirection direction) override;

			Torpedo(BulletType type);
			~Torpedo();
		};
	}
}