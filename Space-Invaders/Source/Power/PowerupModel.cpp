#include "../../Header/Power/PowerupModel.h"


namespace PowerUp
{

	PowerupModel::PowerupModel(PowerType type)
	{
		power_type = type;
	}

	PowerupModel::~PowerupModel()
	{
	}


	void PowerupModel::initialize(sf::Vector2f initialPosition)
	{
		powerup_position = initialPosition;
	}

	void PowerupModel::update()
	{
	}

	void PowerupModel::render()
	{
	}

	sf::Vector2f PowerupModel::getCollectiblePosition()
	{
		return powerup_position;
	}

	void PowerupModel::setCollectiblePosition(sf::Vector2f position)
	{
		powerup_position = position;
	}

	PowerType PowerupModel::getPowerType()
	{
		return power_type;
	}

	void PowerupModel::setPowerType(PowerType type)
	{
		power_type = type;
	}

	float PowerupModel::getMovementSpeed()
	{
		return powerup_speed;
	}

	void PowerupModel::setMovementSpeed(float speed)
	{
		powerup_speed = speed;
	}

}
