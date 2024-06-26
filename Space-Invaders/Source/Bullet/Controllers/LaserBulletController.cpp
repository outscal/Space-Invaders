#include "../../Header/Bullet/Controllers/LaserBulletController.h"


namespace Bullet
{
	namespace Controller
	{
		Bullet::Controller::LaserBulletController::LaserBulletController(BulletType type):BulletController(type)
		{

		}
		LaserBulletController::~LaserBulletController()
		{
		}
		void LaserBulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			BulletController::initialize(position,direction);
		}
	}
}

