#include <iostream>
using namespace std;
#include "../HeaderFiles/GameService.h"


	void GameService::initialize() // initialization of game 
	{
		service_locator->initialize();
		initializeVariables();//INitialize variables

	}
	void GameService::destroy() // Destroys game objects when destroyed 
	{
		delete(game_window);
	}
	void GameService::initializeVariables() {
		game_window = service_locator->GetGraphicService()->GetGameWindow(); //set game window (it was null before this)

	}
	GameService::GameService() // Default Constructor 
	{
		service_locator = nullptr; 
		game_window = nullptr; // Initializes game window pointer to null
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
	void GameService::ignite(){ // Initiates the game 
		service_locator = ServiceLocator::getInstance();
		initialize();
	
	}
	void GameService::render() { //Renders each object each frame
		game_window->clear(service_locator->GetGraphicService()->GetWindowColor());
		service_locator->render();
		game_window->display();

	}
	bool GameService::isRunning() // Keeps on checking if the game is running
	{

		return game_window ->isOpen();
	}


	

	
