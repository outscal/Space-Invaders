#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

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

private:
	sf::Event game_event;
	sf::RenderWindow* game_window;

	bool isGameWindowOpen();
	bool gameWindowClosed();
	bool hasQuitGame();

};

