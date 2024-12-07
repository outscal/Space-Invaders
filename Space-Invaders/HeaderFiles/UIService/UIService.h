#pragma once
#include "../../HeaderFiles/UIService/MainMenuUIController/MainMenuUIController.h"
#include <iostream>
using namespace std;

namespace UI {
	class UIService
	{

		MainMenu::MainMenuUIController* mainMenuUIController;

	private:
		void destroy();
		void createUIControllers();
		void initializeControllers();


	public:

		UIService();
		~UIService();

		void update();
		void initialize();
		void render();



	};
}
