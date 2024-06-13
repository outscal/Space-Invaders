#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include <algorithm>

namespace Player
{
	using namespace Global;
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		processInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::processInput()
	{
		Event::EventService* eventService = ServiceLocator::getInstance()->getEventService();
	/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveRight();
		}*/
		if (eventService->pressLeftKey() || eventService->pressAKey())
		{
			moveLeft();
		}

		if (eventService->pressRightKey() || eventService->pressAKey())
		{
			moveRight();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();

		current_position.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::max(current_position.x, player_model->left_window.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();

		current_position.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position.x = std::min(current_position.x, player_model->right_window.x);
		//cout << "current : " << current_position.x << endl;
		player_model->setPlayerPosition(current_position);
	}

	sf::Vector2f PlayerController::getPosition()
	{
		return player_model->getPlayerPosition();
	}

}
