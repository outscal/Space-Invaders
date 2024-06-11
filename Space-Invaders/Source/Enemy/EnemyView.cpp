#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

#include "../../Header/Graphic/GraphicService.h"


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
		initializeSprite();
	}

	void Enemy::EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void Enemy::EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
	void EnemyView::initializeSprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path))
		{
			enemy_sprite.setTexture(enemy_texture);
			scaleSprite();
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

