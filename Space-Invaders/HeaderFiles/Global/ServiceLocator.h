#pragma once
#include "../../HeaderFiles/Main/GameService.h"
#include <iostream>
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Event/EventService.h"
#include "../../HeaderFiles/Player/PlayerService.h"
#include "../../HeaderFiles/Time/TimeService.h"
#include "../../HeaderFiles/UIService/UIService.h"

namespace Main {
	class GameService;
}

	namespace Global
	{

		class ServiceLocator {

		private:
			Graphic::GraphicService* graphic_service{ nullptr };
			static ServiceLocator* instance;
			Event::EventService* event_service{ nullptr };
			Player::PlayerService* player_service{ nullptr };
			Time::TimeService* time_service{ nullptr };
			UI::UIService* ui_service{ nullptr };

			ServiceLocator();

			~ServiceLocator();

			void createServices(); 			// Creates instances of all services.
			void clearAllServices(); 		//	Deletes and deallocates memory for all services.


		public:
			static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object)
			void update();
			void initialize();
			void render();

			// Methods to Get Specific Services: 
			Graphic::GraphicService* GetGraphicService();
			Event::EventService* GetEventService();
			Player::PlayerService* GetPlayerService();
			Time::TimeService* GetTimeService();
			UI::UIService* GetUIService();

		};
	}



