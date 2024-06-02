#pragma once
#include "../Header/GraphicService.h"
#include "../EventService.h"

class ServiceLocator
{
private:
	GraphicService* graphicservice;

	ServiceLocator();
	~ServiceLocator();


	void createServices(); 
	void clearAllServices(); 
	EventService* eventServiceInstance;

	




	

public:
	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();
	GraphicService* GetGraphicService();
	EventService* getEventServiceInstance();

	

};

