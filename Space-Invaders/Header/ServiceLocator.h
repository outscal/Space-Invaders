
#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header/PlayerService.h"
#include "../Header/TimeService.h"


class ServiceLocator
{
public:
	ServiceLocator();
	~ServiceLocator();

	static ServiceLocator* getInstance();


	void initialize();
	void update();
	void render();

	GraphicService* getGraphicService();
	EventService* getEventService();
	PlayerService* getPlayerService();
	TimeService* getTimeService();

private:
	GraphicService* graphic_service;
	EventService* event_service;
	PlayerService* player_service;
	TimeService* time_service;

	void createServices();
	void clearAllServices();

	};
