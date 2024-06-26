#pragma once

#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/UIService/interface/IUIController.h"


namespace UI
{
	namespace UIElement
	{
		enum class UIState {
			HIDE,
			VISIBLE
		};
		
		class UIView
		{
		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			virtual void show();
			virtual void hide();

		protected:
			sf::RenderWindow* game_window;
			UIState ui_state;
		};


	}

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


