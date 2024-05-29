#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"


namespace Global 
{	
	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
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
		ui_service = new UIService();
		enemy_service = new EnemyService();
		gameplay_service = new GameplayService();
		element_service = new ElementService();
		sound_service = new SoundService();
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
		ui_service->Initialize();
		enemy_service->Initialize();
		gameplay_service->Initialize();
		element_service->Initialize();
		sound_service->Initialize();
	}
	void ServiceLocator::Update()
	{	//	Updates all services.
		graphic_service->Update();
		time_service->Update();
		event_service->Update();
		//Gameplay Services
		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{	
			gameplay_service->Update();
			player_service->Update();
			enemy_service->Update();
			element_service->Update();
		}
		ui_service->Update();
	}
	void ServiceLocator::Render()
	{
		graphic_service->Render();
		//	Renders using the services
		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->Render();
			player_service->Render();
			enemy_service->Render();
			element_service->Render();
		}
		ui_service->Render();
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
		delete(time_service);
		time_service = nullptr;
		delete(ui_service);
		ui_service = nullptr;
		delete(gameplay_service);
		gameplay_service = nullptr;
		delete(element_service);
		element_service = nullptr;
	}

	GraphicService* ServiceLocator::GetGraphicService() { return graphic_service; }
	EventService* ServiceLocator::GetEventService() { return event_service; }
	PlayerService* ServiceLocator::GetPlayerService() { return player_service; }
	TimeService* ServiceLocator::GetTimeService() { return time_service; }
	UIService* ServiceLocator::GetUIService() { return ui_service; }
	EnemyService* ServiceLocator::GetEnemyService() { return enemy_service; }
	GameplayService* ServiceLocator::GetGameplayService() { return gameplay_service; }
	ElementService* ServiceLocator::GetElementService() { return element_service; }
}
