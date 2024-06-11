#include "header/GameService.h"

int main()
{

    // comment all previous code in main()

    GameService game_service; //create object
    game_service.ignite(); // this will 'ignite' or start the flow of our game

    // while the game is running we will update the game loop
    while (game_service.isRunning())
    {
        game_service.update();
        game_service.render();
    }
    return 0;
}