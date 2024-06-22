#include "../Header/ServiceLocator.h"


//Constructor: Initializes the graphic_service pointer to null and creates services
ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr; // Initialize graphic_service to null
	event_service = nullptr; //initialize event_service to null 
	player_service = nullptr;
	createServices(); //Call createServices to instantiate services
}

//Destructor: Cleans up resources by clearing all services
ServiceLocator::~ServiceLocator(){
	clearAllServices(); // Call clearAllServices to delete any allocated services
}

// Creates services instances, specifically the graphic service in this case.
void ServiceLocator::createServices()
{
	graphic_service - new GraphicService(); // Dynamically create a GraphicService instance
	event_service - new EventService();
	player_service - new PlayerService();
}

//Deletes allocated services to prevent memory leaks. In this case, the graphic service.
void ServiceLocator::clearAllServices()
{
	delete(graphic_service); // Delete the graphic_service instance
	delete(event_service);
	delete(player_service);
}

//Returns a pointer to ServiceLocator.
ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance; 
	return &instance;
}

// Calls initialize on the graphic service, readying it for use.
void ServiceLocator::initialize()
{
	graphic_service->initialize(); //initializes graphic service
	event_service->initialize(); //initialize event service
	player_service->initialize();
}

//updates the state of the graphic service
void ServiceLocator::update()
{
	graphic_service->update(); //Update graphic service
	event_service->update();
	player_service->update();
}

//Renders using the graphic service
void ServiceLocator::render()
{
	graphic_service->render(); //Render graphic service
	//event service does not have anything to render
}

// Returns a pointer to the currently set graphic service
GraphicService* ServiceLocator::getGraphicService() {return graphic_service;}
EventService* ServiceLocator::getEventService() { return event_service; }
PlayerService* ServiceLocator::getPlayerService() { return player_service; }