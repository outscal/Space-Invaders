#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"


namespace Enemy
{
	using namespace Global;
	Enemy::EnemyView::EnemyView()
	{
		game_window = nullptr;
	}

	Enemy::EnemyView::~EnemyView()
	{
	}

	void Enemy::EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeSprite(enemy_controller->getEnemyType());
	}

	void Enemy::EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void Enemy::EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
	void EnemyView::initializeSprite(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(Config::zapper_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(Config::subzero_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::UFO:
			if (enemy_texture.loadFromFile(Config::ufo_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleSprite();
			}
			break;
		case Enemy::EnemyType::THUNDER_SNAKE:
			break;
		default:
			break;
		}
	}
	void EnemyView::scaleSprite()
	{
		enemy_sprite.setScale(
			static_cast<float>(enemy_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_height) / enemy_sprite.getTexture()->getSize().y
		);
	}
}

