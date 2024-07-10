
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "HeaderFiles/GameService.h"

int main() {
    GameService* game_service = new GameService();
   // EventService* event_service = new EventService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();

    }
}


