#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers/UI/MainMenu/MainMenuController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();
	};
}
