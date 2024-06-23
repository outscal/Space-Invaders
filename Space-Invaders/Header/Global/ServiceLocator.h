#pragma once
#include "../../header/Graphic/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Time/TimeService.h"
#include "../../header/UI/UIService.h"
#include"../../header/Enemy/EnemyService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files


namespace Global {
    class ServiceLocator
    {
    private:

        Graphic::GraphicService* graphic_service;
        UI::UIService* ui_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        Enemy::EnemyService* enemy_service;

        
        

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
        Graphic::GraphicService* getGraphicService();
        UI::UIService* getUIService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
      
      

        // Methods to Get Specific Services: 
          // Retrieve the EventService instance
       // GraphicService* getGraphicService();   // Retrieve the GraphicService instance

    };
}