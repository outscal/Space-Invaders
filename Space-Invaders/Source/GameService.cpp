#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"

namespace Main
{
	
	GameState GameService::current_state = GameState::BOOT;
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
		service_locator = Global::ServiceLocator::GetInstance();
		service_locator->Initialize();

		game_window = service_locator->GetGraphicService()->GetGameWindow(); // Initialize game_window
		if (!game_window) {
			std::cerr << "Failed to initialize game window in GameService::Initialize()." << std::endl;
		}
		else {
			std::cout << "Game window initialized in GameService::Initialize()." << std::endl;
		}
		ShowMainMenu();
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

		GameService::Initialize();
		//InitializeVariables();

	}
	// Updates the game logic and game state.
	void GameService::Update()
	{
		// Process Events.
		service_locator->GetEventService()->ProcessEvents();

		// Update Game Logic.
		service_locator->Update();
	}
	// Renders each frame of the game.
	void GameService::Render()
	{
		game_window->clear(service_locator->GetGraphicService()->GetWindowColor());
		service_locator->Render();
		game_window->display();
	}
	void GameService::ShowMainMenu()
	{
		SetGameState(GameState::MAIN_MENU);
	}
	// Checks if the game is currently running.
	bool GameService::isRunning()
	{
		return service_locator->GetGraphicService()->IsGameWindowOpen();
	}
	//Game State : BOOT
	void GameService::SetGameState(GameState new_state) { current_state = new_state; }
	GameState GameService::GetGameState() { return current_state; }
}
