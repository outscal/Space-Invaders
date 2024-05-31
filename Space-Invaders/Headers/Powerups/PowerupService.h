#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collectible\ICollectible.h"

namespace Powerup
{

	class PowerupController;
	enum class PowerupType;

	class PowerupService
	{
	private:
		std::vector<Collectible::ICollectible*> powerup_list;

		PowerupController* CreatePowerup(PowerupType powerup_type);
		void Destroy();

	public:
		PowerupService();
		virtual ~PowerupService();

		void Initialize();
		void Update();
		void Render();


		PowerupController* SpawnPowerup(PowerupType powerup_type, sf::Vector2f position);
		void DestroyPowerup(PowerupController* powerup_controller);
	};
}