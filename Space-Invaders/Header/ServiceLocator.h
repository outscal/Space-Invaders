#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header/PlayerService.h"
// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

class ServiceLocator
{
private:
    PlayerService* player_service;
    GraphicService* graphic_service;
    EventService* event_service;
    // Private Attributes:
    // - event_service: Manages event-related functionalities.
    // - graphic_service: Handles graphics-related tasks.
    // ..........................
    // ..........................

    // Private Constructor and Destructor:

    // Constructor for initializing the ServiceLocator.
    ServiceLocator();

    // Destructor for cleaning up resources upon object deletion.
    ~ServiceLocator();

    // Private Methods:

    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:
    // Public Methods:
    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.
    GraphicService* getGraphicService();
    EventService* getEventService(); 
    PlayerService* getPlayerService();
    // Methods to Get Specific Services: 
      // Retrieve the EventService instance
   // GraphicService* getGraphicService();   // Retrieve the GraphicService instance

};