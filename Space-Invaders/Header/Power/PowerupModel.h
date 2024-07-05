#pragma once
#include <SFML/System/Vector2.hpp>
namespace PowerUp
{
	enum class PowerType;
	class PowerupModel
	{
	public:
		PowerupModel(PowerType type);
		~PowerupModel();

		void initialize(sf::Vector2f initialPosition);
		void update();
		void render();

		sf::Vector2f getCollectiblePosition();
		void setCollectiblePosition(sf::Vector2f position);

		PowerType getPowerType();
		void setPowerType(PowerType type);

		float getMovementSpeed();
		void setMovementSpeed(float speed);

	private:
		sf::Vector2f powerup_position;
		float powerup_speed = 300.f;
		PowerType power_type;
	};
}


