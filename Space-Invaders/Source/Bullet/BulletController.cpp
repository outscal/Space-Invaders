#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h";
#include "../../Header/Bullet/BulletView.h";
#include "../../Header/Global/Config.h";
#include "../../Header/Global/ServiceLocator.h";



namespace Bullet
{
	using namespace Global;
	void Bullet::BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case Bullet::MovementDirection::UP:
			moveUp();
			break;
		case Bullet::MovementDirection::DOWM:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getPosition();

		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setPosition(currentPosition);
	}

	void BulletController::handleOutOfBounds()
	{
	}

	BulletController::BulletController(BulletType type)
	{
		bullet_model = new BulletModel(type);
		bullet_view = new BulletView();
	}

	BulletController::~BulletController()
	{
		delete(bullet_model);
		delete(bullet_view);
	}

	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_model->initialize(position, direction);
		bullet_view->initialize(this);
	}

	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		//bullet_model->update();
		handleOutOfBounds();
	}

	void BulletController::render()
	{
		//bullet_model->render();
		bullet_view->render();
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

}
