#include "../Header/ServiceLocator.h"



ServiceLocator::ServiceLocator() {
    
    graphicservice = nullptr;
    eventServiceInstance = nullptr;
    createServices();
}




void ServiceLocator::createServices() {
    
    graphicservice = new GraphicService();
    eventServiceInstance = new EventService();
}

void ServiceLocator::clearAllServices() {
    delete eventServiceInstance;
    delete graphicservice;

}

ServiceLocator* ServiceLocator::getInstance() {
    static ServiceLocator instance;
    return &instance;
}

ServiceLocator::~ServiceLocator() {
    clearAllServices();
}
   

EventService* ServiceLocator::getEventServiceInstance() {
    return eventServiceInstance;
}



void ServiceLocator::initialize() {
    
    graphicservice->initialize();
    return;
}

void ServiceLocator::update() {
    
    return;
}

void ServiceLocator::render() {
    
    graphicservice->render();
}
GraphicService* ServiceLocator::GetGraphicService()
{
    return  graphicservice;
}
 