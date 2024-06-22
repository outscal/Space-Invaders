#include "../../Header/UIService/UIService.h"
#include "../../Header//Main/GameService.h"

#include <iostream>
using namespace std;


namespace UI
{
	using namespace Interface;
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
		//switch (GameService::getGameState())
		//{
		//	case GameState::MAIN_MENU:
		//		return main_menu_controller->update();
		//		break;
		//}
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->update();
		}
	}

	void UIService::render()
	{
		//switch (GameService::getGameState())
		//{
		//case GameState::MAIN_MENU:
		//	//cout << "Current State";
		//	return main_menu_controller->render();
		//	break;
		//}
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->render();
		}

	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		ui_controller->show();
	}

	

	void UIService::createController()
	{
		main_menu_controller = new MainMenuUIController();
	}

	void UIService::initializeController()
	{
		//cout << "initializing";
		IUIController* ui_controller = getCurrentUIController();
		main_menu_controller->initialize();
	}

	void UIService::destroyController()
	{
		delete(main_menu_controller);
	}

	 IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller;
		default:
			break;
		}
	}

}

