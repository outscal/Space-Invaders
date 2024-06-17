// Header/GameService.h

#pragma once

class GameService {
public:
    // Constructor
    GameService();

    // Destructor
    ~GameService();

    // Public methods
    void Ignite();
    void update();
    void render();
    bool isRunning();

private:
    // Private methods
    void initialize();
    void destroy();
};
