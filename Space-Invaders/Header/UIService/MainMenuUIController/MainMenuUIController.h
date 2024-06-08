#pragma once
#include <SFML/Graphics.hpp>


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize();
			void update();
			void render();

		private:
			sf::RenderWindow* game_window;
		};
	}

}

