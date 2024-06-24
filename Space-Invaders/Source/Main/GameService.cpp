#include "../../Header//Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../Header/UIService/UIService.h"

namespace Main

{
	using namespace Global;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;

	GameState GameService::current_state = GameState::BOOT;

	//Constructor: Initializes pointers to null.
	GameService::GameService()
	{
		service_locator = nullptr; // Set service locator to null
	}

	//Destructor: Calls the destroy function to clean up resources
	GameService::~GameService()
	{
		destroy(); // Clean up and release resources
	}

	//Prepares the game service for use by obtaining the service locator instance and initializing services
	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance(); // Get ServiceLocator
		initialize(); // Initialize services.
	}

	//initialize service locator and other variables
	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showMainMenu();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow(); //set game window, was null before this
	}


	void GameService::showMainMenu()
		{
			setGameState(GameState::MAIN_MENU);
			ServiceLocator::getInstance()->getUIService()->showScreen();
		}

	//Checks if the game is still running by querying the graphic service's window status
	bool GameService::isRunning() 
		{
		//Returns true if the game window is open, indicating the game is still running
		return service_locator->getGraphicService()->isGameWindowOpen();
		}

		//Updates the game logic by delegating to the service locator's update method.
		void GameService::update()
		{
			service_locator->getEventService()->processEvents();

			// Update Game Logic.
			service_locator->update();
		}

		void GameService::render()
		{
		game_window->clear();
		service_locator->render();
		game_window->display();
		}

		void GameService::destroy() { service_locator->deleteServiceLocator(); }

		void GameService::setGameState(GameState new_state) { current_state = new_state; }

		GameState GameService::getGameState() { return current_state; }
		}