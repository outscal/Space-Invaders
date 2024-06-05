#include <iostream>
#include "../Header/GameService.h"
#include "../Header/ServiceLocator.h"
using namespace std;

void GameService::initialize()
{
    cout << "GameService: Initializing..." << ::endl;
    initializeVariables();
}

void GameService::destroy()
{
    cout << "GameService: Cleaning up..." << ::endl;
}

GameService::GameService()
{
    serviceLocator = ServiceLocator::getInstance();
    game_window = nullptr;
    cout << "GameService: Constructor called" << ::endl;
}

GameService::~GameService()
{
    destroy();
    cout << "GameService: Destructor called" << ::endl;
}

void GameService::ignite()
{
    cout << "GameService: Igniting..." << ::endl;
    initialize();
}

void GameService::update()
{
    serviceLocator->update();
}

void GameService::render()
{
    if (game_window != nullptr) {
        game_window->clear(serviceLocator->getGraphicService()->getWindowColor());
        serviceLocator->render();
        game_window->display();
    }
    else {
        cerr << "GameService::render: game_window is null" << ::endl;
    }
}

bool GameService::isRunning()
{
    if (game_window != nullptr) {
        return serviceLocator->getGraphicService()->iSWindowOpen();
    }
    cerr << "GameService::isRunning: game_window is null" << ::endl;
    return false;
}

void GameService::initializeVariables()
{
    serviceLocator->initilize();
    game_window = serviceLocator->getGraphicService()->getGameWindow();
}
