#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"
// Private Attributes:
// - event_service: Manages event-related functionalities.
// - graphic_service: Handles graphics-related tasks.
// ..........................
// ..........................

// Private Constructor and Destructor:


ServiceLocator(){/* Constructor for cleaning up resources upon object deletion.*/}
~ServiceLocator(){/* Destructor for cleaning up resources upon object deletion.*/ }

// Private Methods:
void createServices()
{
	// Creates instances of all services.
}

void clearAllServices(); 
{
	//	Deletes and deallocates memory for all services
}

// Public Methods:
static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

void initialize() 
{
	//	Initializes the ServiceLocator.
}		
void update() 
{
	//	Updates all services.
} 				
void render() 
{
	//	Renders using the services.
} 				
