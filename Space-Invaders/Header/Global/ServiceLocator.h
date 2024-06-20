#pragma once
#include "Event/EventService.h"
#include "Graphic/GraphicService.h"
#include "Time/TimeService.h"
#include "Player/PlayerService.h"
#include "UIService/UIService.h"


namespace Global
{

	class ServiceLocator
	{
	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Player::PlayerService* player_service;
		Time::TimeService* time_service;
		UI::UIService* ui_service;

		ServiceLocator();
		~ServiceLocator();

		void createServices();
		void clearAllServices();

	public:

		static ServiceLocator* getInstance();
		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();
		UI::UIService* getUIService();
	};

}