#include "../../Header/Power/PowerupService.h"

namespace PowerUp
{
	PowerUp::PowerupService::PowerupService()
	{
	}

	PowerupService::~PowerupService()
	{
	}

	void PowerupService::update()
	{
	}

	void PowerupService::render()
	{
	}

	PowerupController* PowerupService::spawnPowerUp(PowerType type, sf::Vector2f position)
	{
		return nullptr;
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
	}



	PowerupController* PowerupService::createPowerUp(PowerType type)
	{
		return nullptr;
	}

	void PowerupService::destroy()
	{
	}

}
