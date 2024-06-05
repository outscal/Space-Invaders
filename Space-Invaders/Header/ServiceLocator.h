#pragma once
#include "../Header/GraphicService.h"

<<<<<<< Updated upstream
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

=======

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

	
>>>>>>> Stashed changes
};

