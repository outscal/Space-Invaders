#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Event 
{	
	enum class ButtonState
	{
		PRESSED, HELD, RELEASED
	};
	class EventService
	{
	private:
		//Game Event
		sf::Event game_event; //event var
		
		//Button States
		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;

		//Game Window
		sf::RenderWindow* game_window; //ptr to our game window
		bool  IsGameWindowOpen();
		bool GameWindowWasClosed(); //for the condition we already had - the title bar cross.
		bool HasQuitGame(); //for our new 'ESC' condition

		//Button States handling
		void UpdateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
		void UpdateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);


	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents(); // while window is open we will check for events
		//KeyBoard
		bool PressedEscapeKey();
		bool IsKeyboardEvent();
		bool PressedLeftKey();
		bool PressedRightKey();
		bool PressedAKey();
		bool PressedDKey();
		//Mouse
		bool PressedLMB();
		bool PressedRMB();
	};
}

