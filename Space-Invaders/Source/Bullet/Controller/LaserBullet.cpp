#include "../../HeaderFiles/Bullet/Controllers/LaserBullet.h"

namespace Bullet
{
	namespace BulletControllers
	{
		LaserBullet::LaserBullet(BulletType type) : BulletController(type)
		{

		}

		LaserBullet::~LaserBullet()
		{

		}

		void LaserBullet::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}