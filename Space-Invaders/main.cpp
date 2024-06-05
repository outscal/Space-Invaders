#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/GameService.h"

using namespace std;

int main()
{
    GameService gameserviceObj;
    gameserviceObj.ignite();

    while (gameserviceObj.isRunning()) {
        gameserviceObj.update();
        gameserviceObj.render();
    }

    return 0;
}
