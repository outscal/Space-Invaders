#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
using namespace std;

PlayerService::PlayerService()
{
	game_window = nullptr;
	game_event = nullptr;
}

PlayerService::~PlayerService() = default;


void PlayerService::initialize()
{

		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePlayerSprite();


	
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getposition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::move(float offsetX)
{
	player_position.x += offsetX;
}

int PlayerService::getMoveSpeed()
{
	return movespeed;
}

sf::Vector2f PlayerService::getposition()
{
	return player_position;
}

void PlayerService::initializePlayerSprite()
{
	
	if (player_texure.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texure);
	}
}

void PlayerService::processPlayerInput()
{
	
	game_event = ServiceLocator::getInstance()->getEventService();
	if (game_event->isKeyboardEvent())
	{
		if (game_event->pressLeftKey())
		{
			move(-1.f * getMoveSpeed());
		}
		if (game_event->pressRightKey())
		{
			move(1.f * getMoveSpeed());
		}
	}

}
