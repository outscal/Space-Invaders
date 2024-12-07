#include "../../HeaderFiles/Gameplay/GameplayController.h"
#include "../../HeaderFiles/Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete (gameplayController);
	}

	void GameplayService::initialize()
	{
		gameplayController->initialize();
	}

	void GameplayService::update()
	{
		gameplayController->update();
	}

	void GameplayService::render()
	{
		gameplayController->render();
	}
}