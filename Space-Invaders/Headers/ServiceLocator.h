#pragma once
// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

class ServiceLocator
{
private:
    // Private Attributes:

    // Private Constructor and Destructor:
    ServiceLocator();
    ~ServiceLocator();

    // Private Methods:
    void createServices();
    void clearAllServices();

public:
    // Public Methods:
    static ServiceLocator* getInstance();

    void initialize();
    void update();
    void render();


};
