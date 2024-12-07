#include <iostream>
using namespace std;
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Main/GameService.h"

namespace Global
{

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
// Initialize the static instance pointer
ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator(){
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	time_service = nullptr;
	ui_service = nullptr;
	enemy_service = nullptr;
	gameplay_service = nullptr;
	element_service = nullptr;
	sound_service = nullptr;


	createServices();
}
ServiceLocator::~ServiceLocator() {

	clearAllServices();
}
// Get the single instance of ServiceLocator
ServiceLocator* ServiceLocator::getInstance() {
	static ServiceLocator instance;
		return &instance;
}
void ServiceLocator::initialize(){
	//initializes the service locator class
	graphic_service->initialize();
	event_service->initialize();
	player_service->initialize();
	time_service->initialize();
	ui_service->initialize();
	enemy_service->initialize();
	gameplay_service->initialize();
	element_service->initialize();
	sound_service->initialize();
}
void ServiceLocator::update() {
	//Keeps on updating services required and updates the game state
	graphic_service->update();
	time_service->update();
	event_service->update();
	

	if (GameService::getGameState() == GameState::GAMEPLAY)
	{
		gameplay_service->update();
		player_service->update();
		enemy_service->update();
		element_service->update();
		
	}
	ui_service->update();
}
void ServiceLocator::render() {
	//Keeps on rendering the new services
	graphic_service->render();
	if (GameService::getGameState() == GameState::GAMEPLAY)
	{
		gameplay_service->render();
		player_service->render();
		enemy_service->render();
		element_service->render();
	
	}
	ui_service->render();


}
void ServiceLocator::createServices() {
	graphic_service = new GraphicService();
	event_service = new EventService();
	player_service = new PlayerService();
	time_service = new TimeService();
	ui_service = new UIService();
	enemy_service = new EnemyService();
	gameplay_service = new GameplayService();
	element_service = new ElementService();
	sound_service = new SoundService();
		;
}
void ServiceLocator::clearAllServices() {
	delete(graphic_service); // Delete the graphic_service instance
	graphic_service = nullptr; // Reset pointer to null to avoid dangling pointer
	delete (event_service);
	event_service = nullptr;
	delete (player_service);
	player_service = nullptr;
	delete(time_service);
	time_service = nullptr;
	delete (ui_service);
	ui_service = nullptr;
	delete(enemy_service);
	enemy_service = nullptr;
	delete(gameplay_service);
	gameplay_service = nullptr;
	delete(element_service);
	element_service = nullptr;
	delete(sound_service);
	sound_service = nullptr;
}

// Returns a pointer to the currently set graphic service.

    GraphicService* ServiceLocator::GetGraphicService() 
{ return graphic_service; }
    EventService* ServiceLocator::GetEventService() 
{ return event_service; }
    PlayerService* ServiceLocator::GetPlayerService() 
{ return player_service; }
    TimeService* ServiceLocator::GetTimeService()
{ return time_service; }
	UIService* ServiceLocator::GetUIService(){
		return ui_service;
	}
	EnemyService* ServiceLocator::GetEnemyService() {
		return enemy_service;
	}
	GameplayService* ServiceLocator::GetGameplayService() {
		return gameplay_service;
	}

	ElementService* ServiceLocator::GetElementService()
	{
		return element_service;
	}

	SoundService* ServiceLocator::GetSoundService()
	{
		return sound_service;
	}


}

 //ServiceLocator:: static ServiceLocator* getInstance() {

//}
