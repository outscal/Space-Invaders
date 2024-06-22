#include "../../Header/Power/PowerupView.h"
#include "../../Header/Power/PowerupController.h"
#include "../../Header/Power/PowerConfig.h"
#include "../../Header/Power/PowerupModel.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace PowerUp
{
	using namespace Global;

	PowerupView::PowerupView()
	{
	}

	PowerUp::PowerupView::~PowerupView()
	{
	}

	void PowerUp::PowerupView::initialize(PowerupController* controller)
	{
		power_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initialSprite(power_controller->getPowerType());
	}

	void PowerUp::PowerupView::update()
	{
		powerup_sprite.setPosition(power_controller->getCollectiblePosition());
	}

	void PowerUp::PowerupView::render()
	{
		game_window->draw(powerup_sprite);
	}

	void PowerupView::initialSprite(PowerType type)
	{
		switch (type)
		{
		case PowerUp::PowerType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::TRIPPLE_LASER:
			if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		case PowerUp::PowerType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleSprite();
			}
			break;
		}
	}

	void PowerupView::scaleSprite()
	{
		powerup_sprite.setScale(
			static_cast<float>(powerup_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_height) / powerup_sprite.getTexture()->getSize().y
		);
	}



}
