#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;
	class BulletModel
	{
	public:
		BulletModel(BulletType type);
		~BulletModel();

		void initialize(sf::Vector2f position, Bullet::MovementDirection direction);
		void update();
		void render();

	private:
		float movement_speed = 300.f;
		sf::Vector2f bullet_position;

		BulletType bullet_type;
		MovementDirection movement_type;

		float getMovementSpeed();
		void setMovementSpeed(float speed);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f psoition);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);
	};
}


