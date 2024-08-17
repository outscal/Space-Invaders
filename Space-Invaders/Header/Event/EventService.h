#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
private:
	sf::Event gameEvent;
	sf::RenderWindow* gameWindow;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();


public:
	EventService();
	~EventService();



	void Initialize();
	void Update();
	void ProcessEvents();
	bool PressedEscapeKey();
	bool isKeyboardEvent();

	bool pressedLeftKey();
	bool pressedRightKey();
};