#include "../../HeaderFiles/Gameplay/GameplayView.h"
#include "../../HeaderFiles/Gameplay/GameplayController.h"

namespace Gameplay
{

	GameplayController::GameplayController()
	{
		gameplayView = new GameplayView();
	}

	GameplayController::~GameplayController() 
	{
		delete(gameplayView);
	}

	void GameplayController::initialize()
	{
		gameplayView->initialize();
	}

	void GameplayController::update()
	{
		gameplayView->update();
	}

	void GameplayController::render()
	{
		gameplayView->render();
	}

}