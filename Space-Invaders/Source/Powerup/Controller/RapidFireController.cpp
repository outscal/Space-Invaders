#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controller
	{
		using namespace Global;
		RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}
		RapidFireController::~RapidFireController()
		{

		}
		void RapidFireController::onCollected()
		{

		}
		void RapidFireController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableRapidFire();
		}
	}
}
