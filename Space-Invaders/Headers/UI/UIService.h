#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\MainMenu\MainMenuUIController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\Interface\IUIController.h"
#include <SFML/Graphics.hpp>
namespace UI
{
	using namespace Interface;
	//class IUIController;
	class UIService
	{
	private:
		UI::MainMenu::MainMenuUIController* main_menu_controller;
		//IUIController* main_menu_controller;
		void CreateControllers();
		void InitializeControllers();
		void Destroy();


	public:
		UIService();
		~UIService();
		void Initialize();
		void Update();
		void Render();

		void ShowScreen();

		IUIController* GetCurrentUIController();
	};
}	
namespace UI
{
	namespace UIElement
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};
		class UIView
		{
		protected:
			sf::RenderWindow* game_window;
			UIState ui_state;

		public:
			UIView();
			virtual ~UIView();

			virtual void Initialize();
			virtual void Update();
			virtual void Render();

			virtual void Show();
			virtual void Hide();
		};
	}
}
	

