#include "../../HeaderFiles/Bullet/BulletConfig.h"
#include "../../HeaderFiles/Bullet/BulletController.h"
#include "../../HeaderFiles/Bullet/BulletView.h"
#include "../../HeaderFiles/Global/config.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;
	BulletView::BulletView()
	{

	}

	BulletView::~BulletView()
	{

	}

	void BulletView::initialize(BulletController* controller)
	{
		controller = bulletController;
		window = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		scaleBulletSprite();
	}

	void BulletView::update()
	{

	}
	void BulletView::render()
	{

	}

	void BulletView::initializeBulletSprite(BulletType type)
	{
		switch (type)
		{
		case Bullet::BulletType::LASERBULLET:

			if (bulletTexture.loadFromFile(Config::laserbulletTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleBulletSprite();
			}
			break;
		case Bullet::BulletType::FROSTBULLET:
			if (bulletTexture.loadFromFile(Config::frostbulletTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleBulletSprite();
			}
			break;
		case Bullet::BulletType::TORPEDO:
			if (bulletTexture.loadFromFile(Config::torpedoTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleBulletSprite();
			}
			break;
		default:
			break;
		}
	}

	void BulletView::scaleBulletSprite()
	{
		bulletSprite.setScale(
			static_cast<float>(bulletSpriteHeight) / bulletSprite.getTexture()->getSize().y,
			static_cast<float>(bulletSpriteWidth) / bulletSprite.getTexture()->getSize().x);
	}


}