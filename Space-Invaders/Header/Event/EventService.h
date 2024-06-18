#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Event {
    enum class ButtonState
    {
        PRESSED,
        HELD,
        RELEASED,
    };

    class EventService
    {

        
    private:
        ButtonState left_mouse_button_state;
        ButtonState right_mouse_button_state;
        ButtonState left_arrow_button_state;
        ButtonState right_arrow_button_state;
        ButtonState A_button_state;
        ButtonState D_button_state;
        sf::Event game_event; // Event variable
        sf::RenderWindow* game_window; // Pointer to our game window

        bool isGameWindowOpen() const;
        bool gameWindowWasClosed() const; // For the condition we already had - the title bar cross
        bool hasQuitGame() const; // For our new 'ESC' condition
        void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
        void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
    public:
        EventService();
        ~EventService();
        bool pressedAKey();
        bool pressedDKey();
        bool pressedLeftKey();
        bool pressedRightKey();
        bool pressedLeftMouseButton();
        bool pressedRightMouseButton();

        void initialize();
        void update();
        void processEvents(); // While the window is open, we will check for events
        bool pressedEscapeKey() const;
        bool isKeyboardEvent() const;
       
    };
}
