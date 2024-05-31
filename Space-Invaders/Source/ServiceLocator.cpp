#include <iostream>
#include "../Header/ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
	//construct
}

ServiceLocator::~ServiceLocator()
	{
		//deconstructor
	}

void ServiceLocator::createServices()
{
	// Creates instances of all services.
}

void ServiceLocator::clearAllServices()
{
	//	Deletes and deallocates memory for all services.
}

void ServiceLocator::getInstance()
{
	// Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.
}

void ServiceLocator::initialize()
{
	//	Initializes the ServiceLocator.
}

void ServiceLocator::update()
{
	//	Updates all services.
}

void ServiceLocator::render()
{
	//	Renders using the services.
}
