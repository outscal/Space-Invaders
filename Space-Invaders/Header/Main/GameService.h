#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
   
    enum class GameState //create the enum
    {
        BOOT,
        MAIN_MENU,
        GAMEPLAY,
    };
    class ServiceLocator;
    class GameService
    {
    private:
       Global:: ServiceLocator* service_locator;
        sf::RenderWindow* game_window;
        static GameState current_state;
        void showMainMenu();
        void initialize();
        void initializeVariables(); // Handles game initialization.
        void destroy(); // Handles cleanup tasks.

    public:
        GameService(); // Constructor for initializing the GameService object.
        ~GameService(); // Destructor for cleaning up resources upon object deletion.
        static void setGameState(GameState new_state);
        static GameState getGameState();
        void ignite(); // Initiates the game.
        void update(); // Updates the game logic and game state.
        void render(); // Renders each frame of the game.
        bool isRunning(); // Checks if the game is currently running.
    };
}
