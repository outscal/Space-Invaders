#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;
	using namespace Time;
	using namespace Player;


	//Constructor: Initializes the graphic_service pointer to null and creates services
	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr; // Initialize graphic_service to null
		time_service = nullptr;
		event_service = nullptr; //initialize event_service to null 
		player_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;

		createServices(); //Call createServices to instantiate services
	}

	//Destructor: Cleans up resources by clearing all services
	ServiceLocator::~ServiceLocator() {
		clearAllServices(); // Call clearAllServices to delete any allocated services
	}

	// Creates services instances, specifically the graphic service in this case.
	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService(); // Dynamically create a GraphicService instance
		time_service = new TimeService();
		event_service = new EventService();
		player_service = new PlayerService();
		ui_service = new UIService();

	}
	// Calls initialize on the graphic service, readying it for use.
	void ServiceLocator::initialize()
	{
		graphic_service->initialize(); //initializes graphic service
		time_service->initialize();
		event_service->initialize(); //initialize event service
		player_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->update();
			enemy_service->update();
		}

		ui_service->update();
	}

	//Renders using the graphic service
	void ServiceLocator::render()
	{
		graphic_service->render();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->render();
			enemy_service->render();
		}

		ui_service->render();
	}


	//Deletes allocated services to prevent memory leaks. In this case, the graphic service.
	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(player_service);
		delete(event_service);
		delete(graphic_service); 
		delete(time_service);
	}

	//Returns a pointer to ServiceLocator.
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	// Returns a pointer to the currently set graphic service
	EventService* ServiceLocator::getEventService() { return event_service; }
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }
	Player::PlayerService* ServiceLocator::getPlayerService() { return player_service; }
	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }

}