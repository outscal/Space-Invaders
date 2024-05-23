#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"

// Constructor for initializing the GameService object.
GameService::GameService()
{
	service_locator = nullptr;
	game_window = nullptr;
}
// Destructor for cleaning up resources upon object deletion.
GameService::~GameService()
{
	Destroy();
}
void GameService::Initialize()	
{
	
}
// Handles game initialization.
void GameService::InitializeVariables()
{

}
// Handles cleanup tasks.
void GameService::Destroy()
{

}
// Initiates the game.
void GameService::Ignite()
{
	service_locator = ServiceLocator::GetInstance();
	Initialize();
}
// Updates the game logic and game state.
void GameService::Update()
{
	service_locator->Update();
}
// Renders each frame of the game.
void GameService::Render()
{
	game_window->clear(service_locator->GetGraphicService()->GetWindowColor());
	service_locator->Render();
	game_window->display();
}
// Checks if the game is currently running.
bool GameService::isRunning()
{
	return service_locator->GetGraphicService()->IsGameWindowOpen();
}