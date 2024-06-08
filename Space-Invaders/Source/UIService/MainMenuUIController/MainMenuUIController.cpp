#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Main/GameService.h";


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Event;
		using namespace Graphic;
		using namespace Main;

		MainMenuUIController::MainMenuUIController()
		{
			game_window = nullptr;
		}

		MainMenuUIController::~MainMenuUIController()
		{
		}
		void MainMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}
		void MainMenuUIController::update()
		{
		}
		void MainMenuUIController::render()
		{
		}
	}

}

