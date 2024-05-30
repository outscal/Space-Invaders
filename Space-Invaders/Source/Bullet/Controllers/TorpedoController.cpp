#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\Controllers\TorpedoController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		TorpedoController::TorpedoController(BulletType type) : BulletController(type) { }

		TorpedoController::~TorpedoController() { }

		void TorpedoController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bullet_model->SetMovementSpeed(torpedo_movement_speed);
		}
	}
}