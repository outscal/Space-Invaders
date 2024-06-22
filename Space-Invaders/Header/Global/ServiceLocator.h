#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header//Time/TimeService.h"

//ServiceLocator Class Summary: This class manages access to various services in the application. 
//include relevant headers files as created/needed

class ServiceLocator
{
private:
	// Private Attributes:
	EventService* event_service;
	GraphicService* graphic_service;
	PlayerService* player_service;
	TimeService* time_service;
		// .... and so on


	// Private constructor and destructor:

	// Constructor for initializing the ServiceLocator.
	ServiceLocator();

	// Destructor for cleaning up resources upon object deletion.
	~ServiceLocator();

	// Private Methods:
	void createServices(); //Create instances of all services.
	void clearAllServices(); //Deletes and deallocates memory for all services.

public:
	// Public Methods:
	static ServiceLocator*getInstance(); // Provides a method to access the unique ServiceLocator instance (object). This will be discussed later.
	void initialize(); // Initializes the ServiceLocator.
	void update(); // Updates all services.
	void render(); // Renders using the services.

	//Methods to get Specific Services:
	EventService* getEventService(); // Retrieve the EventService instance
	GraphicService* getGraphicService(); // Retrieve the GraphicService instance
	PlayerService* getPlayerService();
	TimeService* getTimeService();
};