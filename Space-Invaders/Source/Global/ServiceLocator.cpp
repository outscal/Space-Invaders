#include <iostream>
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Main/GameService.h"

using namespace std;


namespace Global
{
	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Main;


	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		player_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		player_service->initialize();


	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();
		ui_service->update();
		/*if (GameService::getGameState() == GameState::GAMEPLAY)
		{*/
			player_service->update();

	/*	}*/
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		ui_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->render();

		}
		
	}

	Graphic::GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	Event::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	Player::PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	Time::TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	UI::UIService* ServiceLocator::uiService()
	{
		return ui_service;
	}


	void ServiceLocator::createServices()
	{
		graphic_service = new Graphic::GraphicService();
		time_service = new Time::TimeService();
		event_service = new Event::EventService();
		ui_service = new UI::UIService();
		player_service = new Player::PlayerService();

	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(time_service);
		delete(event_service);
		delete(ui_service);
		delete(player_service);

		//player_service = nullptr;

	}

}
