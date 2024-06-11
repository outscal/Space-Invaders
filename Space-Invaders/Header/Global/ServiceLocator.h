
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UIService/UIService.h"
#include "../../Header/Enemy/EnemyService.h";


namespace Global
{
	class GraphicService;
	class EventService;
	class PlayerService;
	class TimeService;
	class UIService;
	class EnemyService;

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
		UI::UIService* uiService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();
		Enemy::EnemyService* getEnemyService();

	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		UI::UIService* ui_service;
		Player::PlayerService* player_service;
		Enemy::EnemyService* enemy_service;
		Time::TimeService* time_service;
		void createServices();
		void clearAllServices();

	};

}
