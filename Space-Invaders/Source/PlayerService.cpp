#include "PlayerService.h"
#include "ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;


void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initalizePlayerSprite();
}


void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();
	
	if (event_service->isKeyboardEvent())
	{
		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}
		if(event_service->pressedRightKey())
		{
			moveRight();
		}
	}
}

void PlayerService::initalizePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

/*void PlayerService::move(float offsetX) {
position.x += offsetX;
}*/

void PlayerService::moveLeft()
{
	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::moveRight()
{
	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

sf::Vector2f PlayerService::getPosition() { return position; }
float PlayerService::getMoveSpeed() { return movement_speed; }