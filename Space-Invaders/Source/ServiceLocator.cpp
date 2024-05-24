#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	time_service = nullptr;

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
	std::cout << "Creating Services...\n";
	graphic_service = new GraphicService();
	event_service = new EventService();	
	player_service = new PlayerService();
	time_service = new TimeService();
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
	time_service->Initialize();
	event_service->Initialize();
	player_service->Initialize();
}		
void ServiceLocator::Update()
{	//	Updates all services.
	graphic_service->Update();
	time_service->Update();
	event_service->Update();
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
	event_service = nullptr;
	delete(graphic_service);
	graphic_service = nullptr;
	delete(player_service);
	player_service = nullptr;
	delete(time_service);//remove if error
	time_service = nullptr;
}

GraphicService* ServiceLocator::GetGraphicService() { return graphic_service; }
EventService* ServiceLocator::GetEventService() { return event_service; }
PlayerService* ServiceLocator::GetPlayerService() { return player_service; }
TimeService* ServiceLocator::GetTimeService() { return time_service; }