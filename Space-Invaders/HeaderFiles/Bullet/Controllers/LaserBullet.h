#pragma once
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Bullet/BulletController.h"

namespace Bullet
{
	namespace BulletControllers
	{

		class LaserBullet: public BulletController
		{
		private:


		public:

			LaserBullet(BulletType type);
			~LaserBullet();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}
