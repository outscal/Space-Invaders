#include "ServiceLocator.h"

ServiceLocator::ServiceLocator()
{ //This is a constructor
}

ServiceLocator::~ServiceLocator()
{ // This is a deconstructor
}

void ServiceLocator::createServices()
{ // Creates an instance of all services
}

void ServiceLocator::clearAllServices()
{ //Clears and deallocates memory for all services
}

ServiceLocator* ServiceLocator::getInstance()
{
	//allows us to access the unique ServiceLocator instance (object).
}

void ServiceLocator::initialize()
{ // Initializing service locator
}

void ServiceLocator::update()
{ //updates all services
}

void ServiceLocator::render()
{ //Renders using all services 
}
