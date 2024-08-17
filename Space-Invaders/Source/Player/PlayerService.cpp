#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Global\ServiceLocator.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"

PlayerService::PlayerService()
{
	playerController = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete (playerController);
}

void PlayerService::initialize()
{
	playerController->initialize();
}

void PlayerService::update()
{
	playerController->update();
}

void PlayerService::render()
{
	playerController->render();
}
