#include <iostream>
using namespace std;
#include "../../HeaderFiles/Global/ServiceLocator.h"

namespace Global
{

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;

// Initialize the static instance pointer
ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator(){
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	time_service = nullptr;

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
	//game_service->
}
void ServiceLocator::update() {
	//Keeps on updating services required and updates the game state
	graphic_service->update();
	event_service->update();
	player_service->update();
	time_service->update();

}
void ServiceLocator::render() {
	//Keeps on rendering the new services
	graphic_service->render();
	player_service->render();


}
void ServiceLocator::createServices() {
	graphic_service = new GraphicService();
	event_service = new EventService();
	player_service = new PlayerService();
	time_service = new TimeService();

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


}

 //ServiceLocator:: static ServiceLocator* getInstance() {

//}
