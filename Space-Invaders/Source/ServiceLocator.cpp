#include <iostream>
#include "../Header/ServiceLocator.h"
using namespace std;

ServiceLocator* ServiceLocator::getInstance()
{
    static ServiceLocator instance;
    return &instance;
}

ServiceLocator::ServiceLocator()
{
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
    cout << "ServiceLocator: Destroyed" << endl;
}

{
}

{
	
void ServiceLocator::initilize()
{
    createGameService();
}

void ServiceLocator::update()
{
	graphic_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
}

void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphic_service);
	graphic_service = nullptr;
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}
