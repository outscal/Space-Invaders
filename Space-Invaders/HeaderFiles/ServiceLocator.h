#pragma once
#include "../HeaderFiles/GameService.h"
#include <iostream>
using namespace std;


class ServiceLocator {

private:
	ServiceLocator() {

	}
	~ServiceLocator() {

	}

	void createServices(); 			// Creates instances of all services.
	void clearAllServices(); 		//	Deletes and deallocates memory for all services.


public:
	static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.
	void update();
	void initialize();
	void render();

};