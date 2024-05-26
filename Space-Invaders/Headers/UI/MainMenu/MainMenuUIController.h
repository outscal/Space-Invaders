#pragma once
#include <SFML/Graphics.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const sf::String background_texture_path = "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/space_invaders_bg.png";
			const sf::String play_button_texture_path = "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/play_button.png";
			const sf::String instructions_button_texture_path = "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/instructions_button.png";
			const sf::String quit_button_texture_path = "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/quit_button.png";
			
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
			
			void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();
			
			void ScaleAllButtons();
			void ScaleSpecificButton(sf::Sprite* button_to_scale);
			void PositionButtons();
		public:
			MainMenuUIController();
			void Initialize();
			void Update();
			void Render();
		};
	}
}
