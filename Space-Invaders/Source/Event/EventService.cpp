#include <iostream>
#include "../../HeaderFiles/Main/GameService.h"
using namespace std;
#include "../../HeaderFiles/Event/EventService.h"
#include "../../HeaderFiles/Graphic/GraphicService.h"

namespace Event 
{
	using namespace Global;

	EventService::EventService()
	{
		//gameEvent = nullptr;
		gameWindow = nullptr;
	}
	EventService::~EventService()
	{

	}
	void EventService::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
	}
	void EventService::update()
	{
		processEvents();
	}
	void EventService::processEvents()
	{
		if (isGameWindowOpen()) {
			while (gameWindow->pollEvent(gameEvent))
			{
				cout << gameEvent.type;
				if (gameWindowWasClosed() || hasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}

	bool EventService::hasQuitGame()
	{ // only true if the ESC key is pressed and a keyboard event has been registered
		//return (isKeyboardEvent() && pressedEscapeKey());
		if (isKeyboardEvent()) {
			return pressedEscapeKey();
		}

		return false;

	}
	bool EventService::pressedEscapeKey() {
		return (gameEvent.key.code == sf::Keyboard::Escape);

	}
	bool EventService::isKeyboardEvent() {
		return (gameEvent.type == sf::Event::KeyPressed);
	}
	bool EventService::isGameWindowOpen()
	{
		return gameWindow != nullptr;
	}
	bool EventService::gameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}

	bool EventService::pressedLeftKey() {

		return gameEvent.key.code == sf::Keyboard::Left;


	}
	bool EventService::pressedRightKey() {

		return gameEvent.key.code == sf::Keyboard::Right;
	}
}
