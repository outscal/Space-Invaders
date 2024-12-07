#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

class ServiceLocator {
public:
    static ServiceLocator* getInstance();
    void initialize();
    void update();
    void render();
    
    GraphicService* getGraphicService();
    EventService* getEventService();

private:
    GraphicService* graphic_service;
    EventService* event_service;
    ServiceLocator();
    ~ServiceLocator();
    void createServices();
    void clearAllServices();

    static ServiceLocator* instance;
};

#endif // SERVICELOCATOR_H
