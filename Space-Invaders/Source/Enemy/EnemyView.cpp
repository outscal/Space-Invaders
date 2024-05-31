#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;
	
	EnemyView::EnemyView() { }
	EnemyView::~EnemyView() { }

	void EnemyView::InitializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(Global::Config::zapper_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				ScaleEnemySprite();
			}
			break;
		case Enemy::EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(Global::Config::subzero_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				ScaleEnemySprite();
			}
			break;
		case Enemy::EnemyType::UFO:
			if (enemy_texture.loadFromFile(Global::Config::ufo_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				ScaleEnemySprite();
			}
			break;
			/*case Enemy::EnemyType::THUNDER_SNAKE:
			break;*/
		}
		
	}
	void EnemyView::ScaleEnemySprite()
	{
		enemy_sprite.setScale(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}
	void EnemyView::Initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeEnemySprite(enemy_controller->GetEnemyType());//Get the specific enemy type
	}
	void EnemyView::Update()
	{
		enemy_sprite.setPosition(enemy_controller->GetEnemyPosition());
	}
	void EnemyView::Render()
	{
		game_window->draw(enemy_sprite);
	}
}