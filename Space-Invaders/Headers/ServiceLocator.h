#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\EventService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\PlayerService.h"

class ServiceLocator
{
private:
    // Private Attributes:
    GraphicService* graphic_service;
    EventService* event_service;
    PlayerService* player_service;
    // Private Constructor and Destructor:
    ServiceLocator();
    ~ServiceLocator();

    // Private Methods:
    void CreateServices();
    void ClearAllServices();

public:
    // Public Methods:
    static ServiceLocator* GetInstance();

    void Initialize();
    void Update();
    void Render();

    // Methods to Get Specific Services: 
    GraphicService* GetGraphicService();
    EventService* GetEventService();
    PlayerService* GetPlayerService();
};
