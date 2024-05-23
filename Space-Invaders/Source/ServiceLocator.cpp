#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"
// Private Attributes:
// - event_service: Manages event-related functionalities.
// - graphic_service: Handles graphics-related tasks.
// ..........................
// ..........................

// Private Constructor and Destructor:


ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;

	CreateServices();
}
ServiceLocator::~ServiceLocator()
{
	ClearAllServices();
}

// Private Methods:
void ServiceLocator::CreateServices()
{
	// Creates instances of all services.
	graphic_service = new GraphicService(); //heap
	cout << "Success1";
	event_service = new EventService();		//heap
	cout << "Success2";
	player_service = new PlayerService();		//heap
	cout << "Success3";
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
	event_service->Initialize();
	graphic_service->Initialize();
	player_service->Initialize();

}		
void ServiceLocator::Update()
{
	//	Updates all services.
	event_service->Update();
	graphic_service->Update();
	player_service->Update();

} 				
void ServiceLocator::Render()
{
	//	Renders using the services
	graphic_service->Render();
	player_service->Render();
} 			
void ServiceLocator::ClearAllServices()
{
	//	Deletes and deallocates memory for all services
	delete(event_service);
	delete(graphic_service);
	delete(player_service);
}

GraphicService* ServiceLocator::GetGraphicService() { return graphic_service; }
EventService* ServiceLocator::GetEventService() { return event_service; }
PlayerService* ServiceLocator::GetPlayerService() { return player_service; }