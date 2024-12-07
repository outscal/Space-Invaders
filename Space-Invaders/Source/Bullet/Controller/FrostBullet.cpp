#include "../../HeaderFiles/Bullet/BulletModel.h"
#include "../../HeaderFiles/Bullet/Controllers/FrostBullet.h"

namespace Bullet
{
	namespace BulletControllers
	{
		FrostBullet::FrostBullet(BulletType type) : BulletController(type)
		{

		}

		FrostBullet::~FrostBullet()
		{

		}

		void FrostBullet::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bulletModel->setMovementSpeed(frostbulletMovementSpeed);
		}

	}
}