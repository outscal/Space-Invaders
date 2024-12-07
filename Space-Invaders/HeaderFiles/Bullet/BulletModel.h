#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{

	enum class BulletType;
	enum class MovementDirection;

	class BulletModel
	{
	private:

		float movementSpeed = 300.0f;
		sf::Vector2f bulletPosition;

		BulletType bulletType;
		MovementDirection movementDirection;

	public:

		BulletModel(BulletType type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);
		void update();
		void destroy();
		void render();


		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		float getMovementSpeed();
		void setMovementSpeed(float speed);
	};
}
