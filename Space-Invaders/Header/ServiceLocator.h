#pragma once
#include "../Header/GraphicService.h"

class ServiceLocator
{
private:
	
	GraphicService* graphic_service;

	//Constructor
	ServiceLocator();

	//Destructor
	~ServiceLocator();

	void createGameService(); //Handles the Intialize of service locator
	void clearAllServices(); //Handles the clearing of service locator

public:
	static ServiceLocator* getInstance();

	void initilize(); //Intialize the service locator
	void update();  //service locator code and its state
	void render(); //render the service locator aatch to the game service

	GraphicService* getGraphicService();

};

