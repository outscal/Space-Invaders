#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"
// Private Attributes:
// - event_service: Manages event-related functionalities.
// - graphic_service: Handles graphics-related tasks.
// ..........................
// ..........................

// Private Constructor and Destructor:


ServiceLocator::ServiceLocator()
{
	/* Constructor for cleaning up resources upon object deletion.*/
	graphic_service = nullptr;
	CreateServices();
}
ServiceLocator::~ServiceLocator()
{
	/* Destructor for cleaning up resources upon object deletion.*/ 
	ClearAllServices();
}

// Private Methods:
void ServiceLocator::CreateServices()
{
	// Creates instances of all services.
	graphic_service = new GraphicService(); //heap
}

void ServiceLocator::ClearAllServices();
{
	//	Deletes and deallocates memory for all services
	delete(graphic_service); // Delete the graphic_service instance
	graphic_service = nullptr; // Reset pointer to null to avoid dangling pointer
}

// Public Methods:
 ServiceLocator* ServiceLocator::GetInstance()  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.
{
	static ServiceLocator sLInstance; // we will discuss what 'static' means at a later time.
	return &sLInstance; // Return address of the instance
}
void ServiceLocator::Initialize()
{
	//	Initializes the ServiceLocator.
	graphic_service->Initialize();
}		
void ServiceLocator::Update()
{
	//	Updates all services.
	graphic_service->Update();
} 				
void ServiceLocator::Render()
{
	//	Renders using the services.
	graphic_service->Render();
} 			

GraphicService* ServiceLocator::GetGraphicService() { return graphic_service; }
