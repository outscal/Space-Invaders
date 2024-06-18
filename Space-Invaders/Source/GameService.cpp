#include "../Header/GameService.h"

int Add(int x, int y) //same function declaration as our header
{
	int z = x + y; //the body or the definition.

	return z;
}


// Start the Game:
	// Initialize all necessary game elements when game starts

// While the game is running, keep iterating the game loop:
	// Fetch Player Inputs
	// Update all game logic for this frame according to fetched inputs
	// Draw all game objects on the game window after they are updated.

// If game ends or is stopped:
	// Clean up all resources

void GameService::initialize()
{ //This gets everything running
}

void GameService::destroy()
{ // This probably cleans up resources (memory, etc)
}

GameService::GameService()
{ // This is a constructor
}

GameService::~GameService()
{ // This is a deconstructor
}

void GameService::ignite()
{ // This gets the game started
}

void GameService::update()
{ // This updates game logic and/or states
}

void GameService::render()
{ // This renders each frame of the game
}

bool GameService::isRunning()
{ //This checks to see if the game is running
	return false; //This was the default return value
}
