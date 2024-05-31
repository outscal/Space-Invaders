#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global/ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global/Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView() { CreateUIElements(); }

	BulletView::~BulletView() { Destroy(); }

	void BulletView::Initialize(BulletController* controller)
	{
		bullet_controller = controller;
		//game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage();
	}

	void BulletView::InitializeImage()
	{
		bullet_image->Initialize(GetBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->GetProjectilePosition());
	}

	void BulletView::Update()
	{
		bullet_image->SetPosition(bullet_controller->GetProjectilePosition());
		bullet_image->Update();
	}

	void BulletView::Render()
	{	

		//game_window->draw(bullet_sprite);
		bullet_image->Render();
	}
	sf::String BulletView::GetBulletTexturePath()
	{
		switch (bullet_controller->GetBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laser_bullet_texture_path;

		case::Bullet::BulletType::FROST_BULLET:
			return Config::frost_beam_texture_path;

		case::Bullet::BulletType::TORPEDO:
			return Config::torpedoe_texture_path;
		}
	}
	void BulletView::Destroy()
	{
		delete(bullet_image);
	}

}