<<<<<<< Updated upstream
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
=======
#include "../Header/GameService.h"
#include "../Header/ServiceLocator.h"

GameService::GameService()
{
	service_locator = nullptr;
	game_window = nullptr;
>>>>>>> Stashed changes
}

GameService::~GameService()
{
<<<<<<< Updated upstream
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
=======
	destroyGameService();
}

void GameService::createGameService()
{
	service_locator->initialize();
	initializeVariables();
>>>>>>> Stashed changes
}

void GameService::initializeVariables()
{
<<<<<<< Updated upstream
    serviceLocator->initilize();
    game_window = serviceLocator->getGraphicService()->getGameWindow();
=======
	game_window = service_locator->getGraphicService()->getGameWindow();
}

void GameService::destroyGameService()
{
	delete(service_locator);
	delete(game_window);
	service_locator = nullptr;
	game_window = nullptr;
}

void GameService::ignite()
{
	service_locator = ServiceLocator::getInstance();
	createGameService();
}

void GameService::update()
{
	service_locator->update();
}

void GameService::render()
{
	game_window->clear(service_locator->getGraphicService()->gameWindowColor());
	service_locator->render();
	game_window->display();
}

bool GameService::isRunning()
{
	return service_locator->getGraphicService()->isGameWindowOpen();
>>>>>>> Stashed changes
}
