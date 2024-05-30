#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type)
	{
		bullet_type = type;
	}

	BulletModel::~BulletModel() { }

	void BulletModel::Initialize(sf::Vector2f position, MovementDirection direction)
	{
		movement_direction = direction;
		bullet_position = position;
	}

	sf::Vector2f BulletModel::GetBulletPosition()
	{
		return bullet_position;
	}

	void BulletModel::SetBulletPosition(sf::Vector2f position)
	{
		bullet_position = position;
	}

	BulletType BulletModel::GetBulletType()
	{
		return bullet_type;
	}

	void BulletModel::SetBulletType(BulletType type)
	{
		bullet_type = type;
	}

	MovementDirection BulletModel::GetMovementDirection()
	{
		return movement_direction;
	}

	void BulletModel::SetMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	float BulletModel::GetMovementSpeed()
	{
		return movement_speed;
	}

	void BulletModel::SetMovementSpeed(float speed)
	{
		movement_speed = speed;
	}
}