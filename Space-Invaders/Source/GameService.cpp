
#include<iostream>
#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

void GameService::initialize()
{
	service_locator = nullptr; // Set service locator to null
	game_window = nullptr; // Set game window to null
}

void GameService::destroy()
{
	//cleanup resources
}

GameService::GameService()
{
	destroy(); // Clean up and release resources
}

GameService::~GameService()
{
	//destructor
}

void GameService::ignite()
{
	service_locator = ServiceLocator::getInstance(); // Get ServiceLocator
	initialize(); // Initialize services
}

void GameService::update()
{
	// Process Events.
	service_locator->getEventService()->processEvents();

	// Updates the game logic and game state
	service_locator->update(); // Call update on the service locator which then updates all its managed service


}

void GameService::render()
{
	// Renders each frame of the game.

	// Clears the game window with the background color provided by the graphic service
	game_window->clear(service_locator->getGraphicService()->getWindowColor());
	service_locator->render(); // Render the current frame using the service locator
	game_window->display(); // Display the rendered frame on the game window



}

bool GameService::isRunning()
{
	// Checks if the game is currently running.
	// Returns true if the game window is open, indicating the game is still running
	return service_locator->getGraphicService()->isGameWindowOpen();
	//return false; //default return
}
