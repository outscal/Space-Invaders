#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupConfig.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletConfig.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView() { CreateUIElements(); }

	PowerupView::~PowerupView() { Destroy(); }

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		//game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage();
	}
	void PowerupView::CreateUIElements()
	{
		powerup_image = new ImageView();
	}
	void PowerupView::InitializeImage()
	{
		powerup_image->Initialize(GetPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->GetCollectiblePosition());
	}
	void PowerupView::Update()
	{
		powerup_image->SetPosition(powerup_controller->GetCollectiblePosition());
		powerup_image->Update();
	}

	void PowerupView::Render()
	{
		//game_window->draw(powerup_sprite);
		powerup_image->Render();
	}
	sf::String PowerupView::GetPowerupTexturePath()
	{
		switch (powerup_controller->GetPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}
	void PowerupView::Destroy()
	{
		delete(powerup_image);
	}
}