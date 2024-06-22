#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

//initialize
void PlayerService::initialize() {
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

//Take player input in update, then set the position
//Order is important for the code below!!
void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerController::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->isKeyboardEvent()) //check if a key has been pressed
	{
		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey())
		{
			moveRight();
		}
	}
}

void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

// New movement methods
void PlayerController::moveLeft()
{
	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerController::moveRight()
{
	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}
}

//helper functions
sf::Vector2f PlayerService::getPlayerPosition() { return position; }
int PlayerService::getMoveSpeed() { return movement_speed; }
