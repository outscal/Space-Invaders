#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Collectible/ICollectible.h"
namespace PowerUp
{
	class PowerupService
	{
		class PowerupController;
		enum class PowerType;
	public:
		PowerupService();
		virtual ~PowerupService();

		void update();
		void render();
		PowerupController* spawnPowerUp(PowerType type, sf::Vector2f position);
		//PowerupController* spawnPowerUp(PowerType type,sf::Vector2f position);
		void destroyPowerup(PowerupController* powerup_controller);

	private:
		std::vector <ICollectible*> collectible_list;
		PowerupController* createPowerUp(PowerType type);
		void destroy();
	};


}
