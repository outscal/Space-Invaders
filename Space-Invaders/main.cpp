#include "../../Header/Main/GameService.h"


int main() 
{
    using namespace Main;

    GameService* game_service = new GameService(); //create object

    game_service->ignite(); // "ignites"/starts the flow of our game

    //while the game is running we will update the game loop
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }
    return 0;
}

