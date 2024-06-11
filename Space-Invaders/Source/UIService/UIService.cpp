#include "../../Header/UIService/UIService.h"
#include "../../Header//Main/GameService.h"

#include <iostream>
using namespace std;


namespace UI
{
	using  namespace MainMenu;
	using namespace Main;
	UIService::UIService()
	{
		main_menu_controller = nullptr;
		createController();
	}

	UIService::~UIService()
	{
		destroyController();
	}

	void UIService::initialize()
	{

		initializeController();
	}

	void UIService::update()
	{
		switch (GameService::getGameState())
		{
			case GameState::MAIN_MENU:
				return main_menu_controller->update();
				break;
		}
	}

	void UIService::render()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			//cout << "Current State";
			return main_menu_controller->render();
			break;
		}
	}

	

	void UIService::createController()
	{
		main_menu_controller = new MainMenuUIController();
	}

	void UIService::initializeController()
	{
		//cout << "initializing";
		main_menu_controller->initialize();
	}

	void UIService::destroyController()
	{
		delete(main_menu_controller);
	}

}

