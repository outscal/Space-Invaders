#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global/ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global/Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;

	BulletView::BulletView() {  }

	BulletView::~BulletView() { }

	void BulletView::Initialize(BulletController* controller)
	{
		bullet_controller = controller;
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage(bullet_controller->GetBulletType());
	}

	void BulletView::InitializeImage(BulletType type)
	{
		switch (type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bullet_texture.loadFromFile(Config::laser_bullet_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::FROST_BULLET:
			if (bullet_texture.loadFromFile(Config::frost_beam_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::TORPEDO:
			if (bullet_texture.loadFromFile(Config::torpedoe_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				ScaleImage();
			}
			break;
		}
	}

	void BulletView::ScaleImage()
	{
		bullet_sprite.setScale(
			static_cast<float>(bullet_sprite_width) / bullet_sprite.getTexture()->getSize().x,
			static_cast<float>(bullet_sprite_height) / bullet_sprite.getTexture()->getSize().y
		);
	}

	void BulletView::Update()
	{
		bullet_sprite.setPosition(bullet_controller->GetProjectilePosition());
	}

	void BulletView::Render()
	{	

		game_window->draw(bullet_sprite);
	}

}