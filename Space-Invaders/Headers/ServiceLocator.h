#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"

class ServiceLocator
{
private:
    // Private Attributes:
    GraphicService* graphic_service;
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


};
