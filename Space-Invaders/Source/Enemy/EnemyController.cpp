#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"



namespace Enemy
{
	using namespace Global;
	EnemyController::EnemyController()
	{
		enemy_model = new EnemyModel();
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		enemy_view->update();
		move();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection())
		{
		case Enemy::MovementDirection::LEFT:
			moveLeft();
			break;
		case Enemy::MovementDirection::RIGHT:
			moveRight();
			break;
		case Enemy::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f current_position = enemy_model->getEnemyPosition();
		current_position.x -= enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.x <= enemy_model->left_window.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setRefPosition(current_position);
		}
		else
		{
			enemy_model->setEnemyPosition(current_position);
		}
	}

	void EnemyController::moveRight()
	{
		sf::Vector2f current_position = enemy_model->getEnemyPosition();
		current_position.x += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.x >= enemy_model->right_window.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setRefPosition(current_position);
		}
		else
		{
			enemy_model->setEnemyPosition(current_position);
		}
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f current_position = enemy_model->getEnemyPosition();
		current_position.y += enemy_model->move_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.y >= enemy_model->getRefPosition().y + enemy_model->down_distance)
		{
			if (enemy_model->getRefPosition().x <= enemy_model->left_window.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				
			}
			else
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);

			}
		}
		else
		{
			enemy_model->setEnemyPosition(current_position);
		}
	}
	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}
}
