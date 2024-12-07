#include "../../HeaderFiles/Bullet/Controllers/TorpedoController.h"
#include "../../HeaderFiles/Bullet/BulletModel.h"

namespace Bullet
{
	namespace BulletControllers
	{
		Torpedo::Torpedo(BulletType type) : BulletController(type)
		{

		}

		Torpedo::~Torpedo()
		{

		}

		void Torpedo::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bulletModel->setMovementSpeed(torpedoMovementSpeed);
		}
	}
}