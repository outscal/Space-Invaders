#include "../../Header/Bullet/Controllers/FrostBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType type) : BulletController(type) { }

		FrostBulletController::~FrostBulletController() { }

		void FrostBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}