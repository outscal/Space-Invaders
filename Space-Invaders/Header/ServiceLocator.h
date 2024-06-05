
#pragma once
#include "../Header/GraphicService.h"


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
private:
	GraphicService* graphic_service;
	void createServices();
	void clearAllServices();

	};
