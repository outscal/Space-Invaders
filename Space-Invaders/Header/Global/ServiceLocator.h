
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"


namespace Global
{
	class GraphicService;
	class EventService;
	class PlayerService;
	class TimeService;

	class ServiceLocator
	{
	public:
		ServiceLocator();
		~ServiceLocator();

		static ServiceLocator* getInstance();


		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();

	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Player::PlayerService* player_service;
		Time::TimeService* time_service;

		void createServices();
		void clearAllServices();

	};

}
