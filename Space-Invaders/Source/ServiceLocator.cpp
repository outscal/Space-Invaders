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
    graphic_service = new GraphicService();
    cout << "ServiceLocator: Created" << ::endl;
}

ServiceLocator::~ServiceLocator()
{
    clearAllServices();
    cout << "ServiceLocator: Destroyed" << endl;
}

void ServiceLocator::createGameService()
{
    graphic_service->initialize();
    cout << "ServiceLocator: GraphicService initialized" << endl;
}

void ServiceLocator::clearAllServices()
{
    delete graphic_service;
    graphic_service = nullptr;
    cout << "ServiceLocator: All services cleared" << ::endl;
}

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

GraphicService* ServiceLocator::getGraphicService()
{
    return graphic_service;
}
