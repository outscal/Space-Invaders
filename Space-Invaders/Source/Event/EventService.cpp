#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"



EventService::EventService()
{
	game_window = nullptr;
}

EventService::~EventService() = default;

void EventService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{
	
}

void EventService::processEvent()
{
	if (isGameWindowOpen())
	{
		while (game_window->pollEvent(game_event))
		{
			if (gameWindowClosed() || hasQuitGame())
			{
				game_window->close();
			}
		}
	}
}

bool EventService::pressEscapeKey()
{
	return game_event.key.code == sf::Keyboard::Escape;

}

bool EventService::isKeyboardEvent()
{
	return game_event.type == sf::Event::KeyPressed;
}

bool EventService::pressLeftKey()
{
	//cout << ( game_event.type == sf::Keyboard::Left);
	return game_event.key.code == sf::Keyboard::Left;
}

bool EventService::pressRightKey()
{
	return game_event.key.code == sf::Keyboard::Right;
}

bool EventService::isGameWindowOpen()
{
	return  game_window != nullptr;
}

bool EventService::gameWindowClosed()
{
	return game_event.type == sf::Event::Closed;
}

bool EventService::hasQuitGame()
{
	return (isKeyboardEvent() && pressEscapeKey());
}
