#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"

namespace Global
{

    /*class GraphicService;
    class EventService;
    class PlayerService;
    class TimeService;*/

    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphic_service;

        UI::UIService* ui_service;

        Event::EventService* event_service;

        Player::PlayerService* player_service;

        Time::TimeService* time_service;

        // Private Constructor and Destructor:
        ServiceLocator();
        // Constructor for initializing the ServiceLocator.
        ~ServiceLocator(); 	// Destructor for cleaning up resources upon object deletion.

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* getInstance(); 			// Provides a method to access the unique ServiceLocator instance (object).
        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Graphic::GraphicService* getGraphicService();
        UI::UIService* getUIService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();

    };
}