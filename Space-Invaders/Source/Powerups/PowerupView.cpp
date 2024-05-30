#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupConfig.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"


namespace Powerup
{
	using namespace Global;

	PowerupView::PowerupView() {  }

	PowerupView::~PowerupView() { }

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage(powerup_controller->GetPowerupType());
	}


	void PowerupView::InitializeImage(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				ScaleImage();
			}
			break;
		}
	}

	void PowerupView::ScaleImage()
	{
		powerup_sprite.setScale(
			static_cast<float>(powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
		);
	}

	void PowerupView::Update()
	{
		powerup_sprite.setPosition(powerup_controller->GetCollectiblePosition());
	}

	void PowerupView::Render()
	{
		game_window->draw(powerup_sprite);
	}
}