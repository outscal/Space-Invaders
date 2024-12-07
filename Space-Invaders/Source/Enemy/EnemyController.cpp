#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Enemy/EnemyView.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
//#include "../../HeaderFiles/Event/EventService.h"
//#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include <iostream>
using namespace std;

namespace Enemy
{
	using namespace Global;
	//using namespace Time;
	//using namespace Event;

	EnemyController::EnemyController(EnemyType setType) {
		enemyModel = new EnemyModel(setType);
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController() {
		delete (enemyView);
		delete (enemyModel);
	}

	void EnemyController::initialize() {
		enemyModel->initialize();
		enemyView->initialize(this);
		//enemyModel->setMovementDirection(MovementDirection::DOWN);
		enemyModel->setEnemyPosition(getRandomInitialPosition());
	}

	void EnemyController::update() {
		move();
		enemyView->update();
		handleOutOfBounds();
	}
	void EnemyController::render() {
		enemyView->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition() {
		return enemyModel->getEnemyPosition();
	}
	EnemyType EnemyController::getEnemyType()
	{
		return enemyModel->getEnemyType();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemyModel->getEnemyState();
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemyModel->rightScreenSide.x - enemyModel->leftScreenSide.x));
		float x_position = x_offset_distance + enemyModel->leftScreenSide.x;
		float y_position = enemyModel->leftScreenSide.x;

		return sf::Vector2f(x_position, y_position);

	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = enemyModel->getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x  ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->GetEnemyService()->destroyEnemy(this);
		}
	}
	/*void EnemyController::moveRight()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.x >= enemyModel->rightScreenSide.x)
		{
			enemyModel->setMovementDirection(MovementDirection::DOWN);
			enemyModel->setReferencePosition(currentPosition);
		}
		else (enemyModel->setEnemyPosition(currentPosition));
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x -= enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.x <= enemyModel->leftScreenSide.x)
		{
			enemyModel->setMovementDirection(MovementDirection::DOWN);
			enemyModel->setReferencePosition(currentPosition);
		}
		else (enemyModel->setEnemyPosition(currentPosition));
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.y += enemyModel->enemyVerticalDistance * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.y >= enemyModel->getReferencePosition().y + enemyModel->enemyVerticalDistance)
		{
			if (enemyModel->getReferencePosition().x <= enemyModel->leftScreenSide.x)
			{
				enemyModel->setMovementDirection(MovementDirection::RIGHT);
			}
			else (enemyModel->setMovementDirection(MovementDirection::LEFT));
		}
				else (enemyModel->setEnemyPosition(currentPosition));

		

	}*/
}