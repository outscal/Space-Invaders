#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"


namespace Event
{
	using namespace Global;
	EventService::EventService()
	{
		game_window = nullptr;
		
		game_event.type = sf::Event::KeyPressed;
	}
	EventService::~EventService() = default;

	void EventService::Initialize()
	{
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	}
	void EventService::Update()
	{
		UpdateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
		UpdateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
		UpdateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
		UpdateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
		UpdateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
		UpdateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
	}
	void EventService::ProcessEvents()
	{
		if (IsGameWindowOpen() == true)
		{
			while (game_window->pollEvent(game_event))
			{
				//Check for window closure
				if (GameWindowWasClosed() || HasQuitGame())
				{
					game_window->close();
				}

			}

		}
	}
	void EventService::UpdateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
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
	void EventService::UpdateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
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

	bool EventService::HasQuitGame() { return (IsKeyboardEvent() && PressedEscapeKey()); }

	bool EventService::IsKeyboardEvent() { if (game_event.type == sf::Event::KeyPressed) { return  true; } else return false; }

	bool EventService::PressedEscapeKey() { if (game_event.key.code == sf::Keyboard::Escape) { return true; } else return false; }

	bool EventService::IsGameWindowOpen() { return game_window != nullptr; }

	bool EventService::GameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

	/*bool EventService::PressedLeftKey() { return game_event.key.code == sf::Keyboard::Left; }

	bool EventService::PressedRightKey() { return game_event.key.code == sf::Keyboard::Right; }
	
	bool EventService::PressedLMB()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left;
	}
	bool EventService::PressedRMB()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
	}*/
	bool EventService::PressedLeftKey() { return left_arrow_button_state == ButtonState::HELD; }
	bool EventService::PressedRightKey() { return right_arrow_button_state == ButtonState::HELD; }
	bool EventService::PressedAKey() { return A_button_state == ButtonState::HELD; }
	bool EventService::PressedDKey() { return D_button_state == ButtonState::HELD; }
	bool EventService::PressedLMB() { return left_mouse_button_state == ButtonState::PRESSED; }
	bool EventService::PressedRMB() { return right_mouse_button_state == ButtonState::PRESSED; }

}
