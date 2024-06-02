#pragma once
#include "../Header/ServiceLocator.h"


class GameService {
private:
    ServiceLocator* serviceLoctor;
    void initialize();
    void destroy();

public:
    GameService(); // Constructor
    ~GameService(); // Destructor

    void Ignite();
    void update();
    void render();
    bool isRunning();
};



