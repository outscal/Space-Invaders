#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event {
	class EventService {                                   
		                                             // (Will take the address of the current_button_state var and the pressed mouse or keyboard button.
		enum buttonState {
			PRESSED,
			HELD,
			RELEASED
		};

	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();

		buttonState leftMouseButtonState;
		buttonState rightMouseButtonState;
		buttonState leftArrowButtonState;
		buttonState rightArrowButtonState;
		buttonState A_ButtonState;
		buttonState D_ButtonState;

		void updateMouseButtonsState(buttonState& currentButtonState, sf::Mouse::Button mouseButton);
		void updateKeyboardButtonsState(buttonState& currentButtonState, sf::Keyboard::Key keyboardButton);

	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyboardEvent();



		bool pressedLeftKey();
		bool pressedRightKey();

		bool pressedAKey();
		bool pressedDKey();

		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();

	};
}