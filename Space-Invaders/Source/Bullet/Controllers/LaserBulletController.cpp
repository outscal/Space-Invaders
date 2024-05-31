#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\Controllers\LaserBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType type) : BulletController(type) { }

		LaserBulletController::~LaserBulletController() { }

		void LaserBulletController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
		}
	}
}