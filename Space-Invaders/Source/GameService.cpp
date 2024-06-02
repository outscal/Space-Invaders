#include "../Header/GameService.h"
#include "../Header/ServiceLocator.h"

// Constructor
GameService::GameService() {
    serviceLoctor = nullptr;
    initialize();
}

// Destructor
GameService::~GameService() {
    destroy();
}

// Private method: initialize
void GameService::initialize() {
    serviceLoctor = ServiceLocator::getInstance();
    // Initialization code goes here
}

// Private method: destroy
void GameService::destroy() {
    // Destruction code goes here
  
}

// Public method: Ignite
void GameService::Ignite() {
    // Ignition code goes here
}

// Public method: update
void GameService::update() {
    // Update code goes here
    serviceLoctor->getEventServiceInstance()->processEvents();
}

// Public method: render
void GameService::render() {
    // Render code goes here
}

// Public method: isRunning
bool GameService::isRunning() {
    // Running status code goes here
    return serviceLoctor->GetGraphicService()->isGameWindowOpen();
}
