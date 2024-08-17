#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Global\ServiceLocator.h"
#include<algorithm>
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerModel.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
PlayerController::PlayerController()
{
	playerModel = new PlayerModel();
	playerView = new PlayerView();
}

PlayerController::~PlayerController()
{
	delete (playerView);
	delete (playerModel);
}
void PlayerController::initialize()
{
	playerModel->Initialize();
	playerView->Initialise(this);
}
void PlayerController::update()
{
	processPlayerInput();
	playerView->Update();
}
void PlayerController::render()
{
	playerView->Render();
}


sf::Vector2f PlayerController::getPlayerPosition()
{
	return playerModel->getPlayerPosition();
}
void PlayerController::processPlayerInput()
{
	EventService* event_service = ServiceLocator::GetInstance()->getEventService();
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		moveLeft();
	}
	// we will move this to event service at a later time
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		moveRight();
	}
}

void PlayerController::moveLeft()
{
	sf::Vector2f currentPosition = playerModel->getPlayerPosition();
	currentPosition.x -= playerModel->playerMovementSpeed * ServiceLocator::GetInstance()->getTimeService()->getDeltaTime();

	currentPosition.x = std::max(currentPosition.x, playerModel->left_most_position.x);
	playerModel->setPlayerPosition(currentPosition);
}

void PlayerController::moveRight()
{
	sf::Vector2f currentPosition = playerModel->getPlayerPosition();
	currentPosition.x +=  playerModel->playerMovementSpeed* ServiceLocator::GetInstance()->getTimeService()->getDeltaTime();

	currentPosition.x = std::min(currentPosition.x, playerModel->right_most_position.x);
	playerModel->setPlayerPosition(currentPosition);
}









