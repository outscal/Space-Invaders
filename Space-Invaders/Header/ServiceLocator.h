#pragma once

class ServiceLocator {
public:
    // Public methods
    static ServiceLocator* getInstance();
    void initialize();
    void update();
    void render();

private:
    // Private methods
    ServiceLocator(); // Constructor
    ~ServiceLocator(); // Destructor
    void createServices();
    void clearAllServices();

    // Singleton instance
    static ServiceLocator* instance;
};
