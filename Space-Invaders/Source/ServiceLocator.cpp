#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphicService = new GraphicService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphicService);
	graphicService = nullptr;
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{	
	graphicService->initialize();
}

void ServiceLocator::update()
{
	graphicService->update();
}

void ServiceLocator::render()
{
	graphicService->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphicService;
}
