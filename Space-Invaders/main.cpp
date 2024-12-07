
#include <iostream>
using namespace std;
#include "../../HeaderFiles/Main/GameService.h"
#include <SFML/Graphics.hpp>

using namespace Main;

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


