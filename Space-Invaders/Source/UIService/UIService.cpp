#include "../../Header/UIService/UIService.h"
#include <iostream>
using namespace std;


namespace UI
{
	using  namespace MainMenu;
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
		main_menu_controller->update();
	}

	void UIService::render()
	{
		main_menu_controller->render();
	}

	void UIService::createController()
	{
		main_menu_controller = new MainMenuUIController();
	}

	void UIService::initializeController()
	{
		cout << "initializing";
		main_menu_controller->initialize();
	}

	void UIService::destroyController()
	{
		delete(main_menu_controller);
	}

}

