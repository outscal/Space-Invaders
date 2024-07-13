#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupModel.h"

namespace Powerup
{
	PowerupModel::PowerupModel(PowerupType type)
	{
		powerup_type = type;
	}

	PowerupModel::~PowerupModel() { }

	void PowerupModel::Initialize(sf::Vector2f position)
	{
		powerup_position = position;
	}

	sf::Vector2f PowerupModel::GetPowerupPosition()
	{
		return powerup_position;
	}

	void PowerupModel::SetPowerupPosition(sf::Vector2f position)
	{
		powerup_position = position;
	}

	PowerupType PowerupModel::GetPowerupType()
	{
		return powerup_type;
	}

	void PowerupModel::SetPowerupType(PowerupType type)
	{
		powerup_type = type;
	}

	float PowerupModel::GetMovementSpeed()
	{
		return movement_speed;
	}

	void PowerupModel::SetMovementSpeed(float speed)
	{
		movement_speed = speed;
	}
}