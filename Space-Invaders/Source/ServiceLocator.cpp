
#include "../Header/Global/ServiceLocator.h"

namespace Global { 

	ServiceLocator::ServiceLocator()
	{
		graphicservice = nullptr;
		eventServiceInstance = nullptr;

		createServices();
	}

	void ServiceLocator::provideEventService(EventService* eventService) {
		eventServiceInstance = eventService;
	}

	EventService* ServiceLocator::getEventServiceInstance()
	{
		return eventServiceInstance;
	}

	void ServiceLocator::createServices()
	{
		graphicservice = new GraphicService();
		eventServiceInstance = new EventService();

	}

	void ServiceLocator::clearAllServices()
	{
		delete eventServiceInstance;
		delete graphicservice;

	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::initialize()
	{
		graphicservice->initialize();
	}

	void ServiceLocator::update()
	{

	}

	void ServiceLocator::render()
	{
		graphicservice->render();
	}

	GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicservice;
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphicservice;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return timeServiceInstance;
	}
}
