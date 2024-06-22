#pragma once

#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/UIService/interface/IUIController.h"


namespace UI
{
	class UIController;

	class UIService
	{
	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();


		void showScreen();
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createController();
		void initializeController();
		void destroyController();

		UI::Interface::IUIController* getCurrentUIController();

	

	};
}


