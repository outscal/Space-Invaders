#pragma once
#include "../../Header/Collectible/ICollectible.h"
namespace PowerUp
{
	class PowerupModel;
	class PowerupView;
	enum class PowerType;

	class PowerupController:public ICollectible
	{
	public:
		PowerupController(PowerType type);
		virtual ~PowerupController();
		
		void initialCollectible(sf::Vector2f collectiblePosition)  override;
		void update() override;
		void render() override;

		void onCollected() override;
		sf::Vector2f getCollectiblePosition() override;

		PowerType getPowerType();

	private:
		PowerupModel* powerup_model;
		PowerupView* powerup_view;

		void UpdatePowerPosition();
		void handleOfBounds();
	};

}
