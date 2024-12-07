#include <iostream>
using namespace std;
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Main/GameService.h"


namespace Main 
{
	using namespace Global;

	GameState GameService::currentState = GameState::BOOT;

	void GameService::initialize() // initialization of game 
	{
		service_locator->initialize();
		initializeVariables();//INitialize variables
		showMainMenu();
	

	}
	void GameService::destroy() // Destroys game objects when destroyed 
	{
		delete(gameWindow);
	}
	void GameService::initializeVariables() {
		gameWindow = service_locator->GetGraphicService()->GetGameWindow(); //set game window (it was null before this)

	}
	GameService::GameService() // Default Constructor 
	{
		service_locator = nullptr;
		gameWindow = nullptr; // Initializes game window pointer to null
		//gameloop
	}
	GameService::~GameService() // Deconstructor
	{
		// end of game when player exits
		destroy();
	}

	void GameService::update() //Updates the game objects each frame 
	{
		service_locator->GetEventService()->processEvents();
		service_locator->update();

	}
	void GameService::ignite() { // Initiates the game 
		service_locator = Global::ServiceLocator::getInstance();
		initialize();


	}
	void GameService::render() { //Renders each object each frame
		gameWindow->clear(service_locator->GetGraphicService()->GetWindowColor());
		service_locator->render();
		gameWindow->display();


	}
	bool GameService::isRunning() // Keeps on checking if the game is running
	{
		return service_locator->GetGraphicService()->isGameWindowOpen();
	}

    void GameService::setGameState(GameState newState) {

		currentState = newState;

	}
     GameState GameService::getGameState() {
		return currentState;
	}

	 void GameService::showMainMenu() {
		 setGameState(GameState::MAINMENU);
	 }
}
		


	

	
