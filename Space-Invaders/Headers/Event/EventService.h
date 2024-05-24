#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
private:
	sf::Event game_event; //event var
	sf::RenderWindow* game_window; //ptr to our game window

	bool  IsGameWindowOpen();
	bool GameWindowWasClosed(); //for the condition we already had - the title bar cross.
	bool HasQuitGame(); //for our new 'ESC' condition

public:
	EventService();
	~EventService();

	void Initialize();
	void Update();
	void ProcessEvents(); // while window is open we will check for events
	bool PressedEscapeKey();
	bool IsKeyboardEvent();
	bool PressedLeftKey();
	bool PressedRightKey();

};
