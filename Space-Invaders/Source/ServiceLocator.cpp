#include <iostream>
#include "../Header/ServiceLocator.h"
using namespace std;

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	graphic_service->initialize();
}

void ServiceLocator::update()
{
	graphic_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
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
