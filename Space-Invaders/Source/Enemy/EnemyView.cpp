#include "../../HeaderFiles/Enemy/EnemyView.h"
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"

#include <iostream>
using namespace std;

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() 
	{

	}

	EnemyView::~EnemyView() {

	}

	void EnemyView::initialize(EnemyController * controller) 
	{
		enemyController = controller;
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		initializeEnemySprites(enemyController->getEnemyType());
	}

	void EnemyView::initializeEnemySprites(EnemyType setType) 
	{
		switch (setType)
		{
		case Enemy::EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(subzero_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				scaleEnemySprites();
			}
			break;
		case Enemy::EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(zapper_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				scaleEnemySprites();
			}
			break;
		case Enemy::EnemyType::THUNDERSNAKE:
			if (enemyTexture.loadFromFile(thundersnake_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				scaleEnemySprites();
			}
		}
	}

	void EnemyView::scaleEnemySprites()
	{
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y);
	}
	void EnemyView::update() {
		enemySprite.setPosition(enemyController->getEnemyPosition());
	}

	void EnemyView::render() {
		gameWindow->draw(enemySprite);
	}


}