#include "../../Header/Gameplay/GameplayController .h"

namespace Gameplay
{
	Gameplay::GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView();
	}

	Gameplay::GameplayController::~GameplayController()
	{
		delete(gameplay_view);
	}
	void GameplayController::initialize()
	{
		gameplay_view->initialize();
	}
	void GameplayController::update()
	{
		gameplay_view->update();
	}
	void GameplayController::render()
	{
		gameplay_view->render();
	}
}


