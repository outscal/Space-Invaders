#pragma once
#include "GraphicService.h"

class ServiceLocator
{
private:
	GraphicService* graphic_service;

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
};
