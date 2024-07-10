#include <iostream>
#include "../HeaderFiles/GameService.h"
using namespace std;
#include "../HeaderFiles/ServiceLocator.h"
#include "../HeaderFiles/EventService.h"


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
				if (gameWindowWasClosed() || hasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}

	bool EventService::hasQuitGame()
	{ // only true if the ESC key is pressed and a keyboard event has been registered
		return (isKeyboardEvent() && pressedEscapeKey());

	}
	bool EventService::pressedEscapeKey() {
		return (gameEvent.key.code == sf::Keyboard::Escape);
	}
	bool EventService::isKeyboardEvent() {
		return gameEvent.type == sf::Event::KeyPressed;
	}
	bool EventService::isGameWindowOpen() 
	{
		return gameWindow != nullptr;
	}
	bool EventService::gameWindowWasClosed() 
	{
		return gameEvent.type = sf::Event::Closed;
	}
	


