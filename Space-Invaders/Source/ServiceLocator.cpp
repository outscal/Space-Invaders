#include "../Header/ServiceLocator.h"

// Constructor: Initializes the graphic_service pointer to null and creates services.
ServiceLocator::ServiceLocator() {
	graphic_service = nullptr; // Initialize graphic_service to null.
	event_service = nullptr; // Initialize event_service to null.
	player_service = nullptr; //Initialize player_service to null.
	time_service = nullptr;  //Initialize time_service to null.
	
	
	createServices(); // Call createServices to instantiate services
}

// Destructor: Cleans up resources by clearing all services.
ServiceLocator::~ServiceLocator() {
	clearAllServices(); // Call clearAllServices to delete any allocated services	
}

// Creates service instances, specifically the graphic service in this case.
void ServiceLocator::createServices() {
	graphic_service = new GraphicService();// Dynamically create a GraphicService instance
	event_service = new EventService();// Dynamically create a EventService instance
	player_service = new PlayerService();// Dynamically create a PlayerService instance
	time_service = new TimeService(); // Dynamically create a TimeService instance

}

// Deletes allocated services to prevent memory leaks, specifically the graphic service.
void ServiceLocator::clearAllServices() {
	delete(graphic_service);// Delete the graphic_service instance
	delete(event_service); // Delete the event_service instance
	delete(player_service);  //Delete the player_service instance
	delete(time_service);   //Delete the time_service instance
}

// Returns a pointer to ServiceLocator.
ServiceLocator* ServiceLocator::getInstance() {
	static ServiceLocator instance; // we will discuss what 'static' means at a later time.
	return &instance; // Return address of the instance
}

// Calls initialize on the graphic service, readying it for use.
void ServiceLocator::initialize() {
	graphic_service->initialize();// Initialize graphic service.
	event_service->initialize();// Initialize event service.
	player_service->initialize();// Initialize player service.
	time_service->initialize(); // Initialize time_service.

}

// Updates the state of the graphic service.
void ServiceLocator::update() {
	graphic_service->update();// Update graphic service
	event_service->update();// Update event service.
	player_service->update();// Update player service
	time_service->update(); // Update time service'
}

// Renders using the graphic service.
void ServiceLocator::render() {
	graphic_service->render(); // Render graphic service
	player_service->render(); //Render Player service
}

// Returns a pointer to the currently set graphic service.
GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
EventService* ServiceLocator::getEventService() { return event_service; }
PlayerService* ServiceLocator::getPlayerService() { return player_service; }
TimeService* ServiceLocator::getTimeService() { return time_service; }
