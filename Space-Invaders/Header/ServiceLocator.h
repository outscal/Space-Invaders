#pragma once

class ServiceLocator
{
private:
	
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

};

