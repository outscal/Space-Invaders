#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
private:
    sf::Event game_event; // Event variable
    sf::RenderWindow* game_window; // Pointer to our game window

    bool isGameWindowOpen() const;
    bool gameWindowWasClosed() const; // For the condition we already had - the title bar cross
    bool hasQuitGame() const; // For our new 'ESC' condition

public:
    EventService();
    ~EventService();

    bool pressedLeftKey();
    bool pressedRightKey();

    void initialize();
    void update();
    void processEvents(); // While the window is open, we will check for events
    bool pressedEscapeKey() const;
    bool isKeyboardEvent() const;
};
