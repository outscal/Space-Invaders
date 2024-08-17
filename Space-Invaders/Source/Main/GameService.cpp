#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Main\GameService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Event\EventService.h"




GameService::GameService()
{
	serviceLocator = nullptr;
	gameWindow = nullptr;


}

GameService::~GameService()
{
	Destroy();

	//destructor
}

void GameService::Ignite()
{
	serviceLocator = ServiceLocator::GetInstance();
	Initialize();

}
void GameService::Initialize()
{
	serviceLocator->Initialize();
	InitializeVariables();
	
}

void GameService::InitializeVariables()
{
	gameWindow =  serviceLocator->getGraphicService()->GetGameWindow();


}

void GameService::Destroy()
{

}








void GameService::Update()
{

	serviceLocator->Update();

	serviceLocator->getEventService()->ProcessEvents();

	serviceLocator->Update();

	//updates the game logic and states

}

void GameService::Render()
{
	gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());
	serviceLocator->Render();
	gameWindow->display();

	//Render things on screen
}

bool GameService::IsGameRunning()
{

	return serviceLocator->getGraphicService()->isGameWindowOpen();
}
