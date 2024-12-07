#pragma once

#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"


namespace UI
{
	class UIService
	{
	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();


	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createController();
		void initializeController();
		void destroyController();
	};
}


