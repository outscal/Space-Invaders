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
		updateMouseButtonsState(leftMouseButtonState, sf::Mouse::Left);
		updateMouseButtonsState(rightMouseButtonState, sf::Mouse::Right);
		updateKeyboardButtonsState(A_ButtonState, sf::Keyboard::A);
		updateKeyboardButtonsState(D_ButtonState, sf::Keyboard::D);
		updateKeyboardButtonsState(leftArrowButtonState, sf::Keyboard::Left);
		updateKeyboardButtonsState(rightArrowButtonState, sf::Keyboard::Right);


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

		return leftArrowButtonState == buttonState::HELD;


	}
	bool EventService::pressedRightKey() 
	{
		return rightArrowButtonState == buttonState::HELD;
	}

	bool EventService::pressedAKey() {
		return A_ButtonState == buttonState::HELD;
	}

	bool EventService::pressedDKey() {
		return D_ButtonState == buttonState::HELD;
	}
	bool EventService::pressedLeftMouseButton() {
		return leftMouseButtonState == buttonState::PRESSED;
	}

	bool EventService::pressedRightMouseButton() {
		return rightMouseButtonState == buttonState::PRESSED;
	}

	void EventService::updateMouseButtonsState(buttonState &curentButtonState, sf::Mouse::Button mouseButton) 
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			switch (curentButtonState)
			{
			case buttonState::RELEASED:
				curentButtonState = buttonState::PRESSED;
				break;

			case buttonState::PRESSED:
				curentButtonState = buttonState::HELD;
				break;
			}
		}
		else
		{
			curentButtonState = buttonState::RELEASED;
		}

	}

	void EventService::updateKeyboardButtonsState(buttonState &currentButtonState, sf::Keyboard::Key keyboardButton) 
	{
		if (sf::Keyboard::isKeyPressed(keyboardButton))
		{
			switch (currentButtonState)
			{
			case buttonState::RELEASED:
				currentButtonState = buttonState::PRESSED;
				break;

			case buttonState::PRESSED:
				currentButtonState = buttonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = buttonState::RELEASED;
		}

		

	}
}
