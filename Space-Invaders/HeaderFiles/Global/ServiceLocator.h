#pragma once
#include "../../HeaderFiles/Main/GameService.h"
#include <iostream>
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Event/EventService.h"
#include "../../HeaderFiles/Player/PlayerService.h"
#include "../../HeaderFiles/Time/TimeService.h"
#include "../../HeaderFiles/UIService/UIService.h"
#include "../../HeaderFiles/Enemy/EnemyService.h"
#include "../../HeaderFiles/Gameplay/GameplayService.h"
#include "../../HeaderFiles/Element/ElementService.h"
#include "../../HeaderFiles/Sound/SoundService.h"

//namespace Main {
	//class GameService;
///}

	namespace Global
	{

		class ServiceLocator {

		private:
			Graphic::GraphicService* graphic_service;
			static ServiceLocator* instance;
			Event::EventService* event_service;
			Player::PlayerService* player_service;
			Time::TimeService* time_service;
			UI::UIService* ui_service;
			Enemy::EnemyService* enemy_service;
			Gameplay::GameplayService* gameplay_service;
			Element::ElementService* element_service;
			Sound::SoundService* sound_service;

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
			Enemy::EnemyService* GetEnemyService();
			Gameplay::GameplayService* GetGameplayService();
			Element::ElementService* GetElementService();
			Sound::SoundService* GetSoundService();
			void deleteServiceLocator();

		};
	}



