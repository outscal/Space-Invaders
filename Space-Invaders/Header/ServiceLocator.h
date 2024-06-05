
#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"


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
private:
	GraphicService* graphic_service;
	EventService* event_service;

	void createServices();
	void clearAllServices();

	};
