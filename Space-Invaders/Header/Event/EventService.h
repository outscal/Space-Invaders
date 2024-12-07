#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


namespace Event
{

	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED
	};
	class EventService
	{
	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvent();
		bool pressEscapeKey();
		bool isKeyboardEvent();
		bool pressLeftKey();
		bool pressRightKey();
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
		bool pressAKey();
		bool pressDKey();


	private:
		sf::Event game_event;
		sf::RenderWindow* game_window;
		ButtonState left__mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_key_button_state;
		ButtonState right_key_button_state;
		ButtonState a_key_button_state;
		ButtonState d_key_button_state;

		void updateMouseState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
		
		bool isGameWindowOpen();
		bool gameWindowClosed();
		bool hasQuitGame();

	};


}
