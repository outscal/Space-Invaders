#include "../../HeaderFiles/Bullet/BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type)
	{
		bulletType = type;
	}

	BulletModel::~BulletModel()
	{

	}

	void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
	{
		movementDirection = direction;

		bulletPosition = position;
	}

	void BulletModel::update()
	{

	}

	void BulletModel::render()
	{

	}

	void BulletModel::destroy()
	{

	}

	BulletType BulletModel::getBulletType()
	{
		return bulletType;
	}

	void BulletModel::setBulletType(BulletType type)
	{
		bulletType = type;
	}

	float BulletModel::getMovementSpeed()
	{
		return movementSpeed;
	}

	void BulletModel::setMovementSpeed(float speed)
	{
		movementSpeed = speed;
	}

	MovementDirection BulletModel::getMovementDirection()
	{
		return movementDirection;
	}

	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}
}