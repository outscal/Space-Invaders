#pragma once
#include <SFML/Graphics.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;
			
			// Textures:
			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture instructions_button_texture;
			sf::Sprite instructions_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;
			//BG Image visual and init.
			void InitializeBackgroundImage();
			void ScaleBackgroundImage();
			//Button visual and init.
			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();
			void ScaleAllButtons();
			void ScaleSpecificButton(sf::Sprite* button_to_scale);
			void PositionButtons();
			//Button Interactions
			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite*, sf::Vector2f);
		public:
			MainMenuUIController();
			void Initialize();
			void Update();
			void Render();
		};
	}
}
