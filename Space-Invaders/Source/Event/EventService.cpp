#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Event
{
	using namespace Global;
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
		updateMouseState(left__mouse_button_state, sf::Mouse::Left);
		updateMouseState(right_mouse_button_state, sf::Mouse::Right);
		updateKeyState(left_key_button_state, sf::Keyboard::Left);
		updateKeyState(right_key_button_state, sf::Keyboard::Right);
		updateKeyState(a_key_button_state, sf::Keyboard::A);
		updateKeyState(d_key_button_state, sf::Keyboard::D);



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
		return left_key_button_state == ButtonState::HELD;/* game_event.type == sf::Keyboard::Left;*/
	}

	bool EventService::pressRightKey()
	{
		return right_key_button_state == ButtonState::HELD;
	}

	bool EventService::pressedLeftMouseButton()
	{
		return left__mouse_button_state == ButtonState::PRESSED;
	}

	bool EventService::pressedRightMouseButton()
	{
		return right_mouse_button_state == ButtonState::PRESSED;
	}

	bool EventService::pressAKey()
	{
		return a_key_button_state == ButtonState::HELD;
	}

	bool EventService::pressDKey()
	{
		return d_key_button_state == ButtonState::HELD;
	}

	void EventService::updateMouseState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			;
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;

			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
		
	}

	void EventService::updateKeyState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
	{
		if (sf::Keyboard::isKeyPressed(keyboard_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
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
}

