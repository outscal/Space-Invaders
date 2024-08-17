#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Global\ServiceLocator.h"




ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
	playerService = nullptr;
	timeService = nullptr;
	CreateServices();
}


ServiceLocator::~ServiceLocator()
{
	ClearAllServices();
	
}

void ServiceLocator::CreateServices()
{
	graphicService = new GraphicService();
	eventService = new EventService();
	playerService = new PlayerService();
	timeService = new TimeService();

}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	graphicService = nullptr;
	delete(eventService);
	eventService = nullptr;
	delete(playerService);
	delete(timeService);

}

ServiceLocator* ServiceLocator::GetInstance()
{
	static ServiceLocator instance;
	return &instance;  // Return address of the instance
}

void ServiceLocator::Initialize()
{
	graphicService->Initialize();
	eventService->Initialize();
	playerService->initialize();
	timeService->initialize();

}

void ServiceLocator::Update()
{
	graphicService->Update();
	eventService->Update();
	playerService->update();
	timeService->update();
}

void ServiceLocator::Render()
{
	graphicService->Render();
	playerService->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphicService;
}

EventService* ServiceLocator::getEventService()
{
	return eventService;
}

PlayerService* ServiceLocator::getPlayerService()
{
	return playerService;
}

TimeService* ServiceLocator::getTimeService()
{
	return timeService;
}

