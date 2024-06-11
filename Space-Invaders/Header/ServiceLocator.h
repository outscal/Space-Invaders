#pragma once
#include "GraphicService.h"
#include "EventService.h"
#include "PlayerService.h"
#include "TimeService.h"

class ServiceLocator
{
private:
	GraphicService* graphic_service;
	EventService* event_service;
	PlayerService* player_service;
	TimeService* time_service;

	ServiceLocator();
	~ServiceLocator();

	void createServices();
	void clearAllServices();

public:

	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();

	GraphicService* getGraphicService();
	EventService* getEventService();
	PlayerService* getPlayerService();
	TimeService* getTimeService();
};
