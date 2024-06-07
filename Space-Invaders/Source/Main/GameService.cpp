#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	using namespace Global;
	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}
	GameService::~GameService()
	{
		destroyGameService();
	}

	void GameService::createGameService()
	{
		service_locator->initialize();
		initializeVariables();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}


	void GameService::ignite()
	{
		service_locator = Global::ServiceLocator::getInstance();
		createGameService();
	}

	void GameService::update()
	{
		service_locator->update();
		service_locator->getEventService()->processEvent();
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getGraphicService()->gameWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}


	void GameService::destroyGameService()
	{
		delete(service_locator);
		delete(game_window);
		service_locator = nullptr;
		game_window = nullptr;
	}
}

