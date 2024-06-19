#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
private:
	sf::Event game_event; //event variable
	sf::RenderWindow* game_window; //pointer to our game window

	bool isGameWindowOpen();
	bool gameWindowWasClosed(); //For condition we had previously
	bool hasQuitGame(); //for our new 'ESC' condition

public:
	EventService();
	~EventService();

	void initialize();
	void update();
	void processEvents(); //while window is open we will check for events
	bool pressedEscapeKey();
	bool isKeyboardEvent();
};