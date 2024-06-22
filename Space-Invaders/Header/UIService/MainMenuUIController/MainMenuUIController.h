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
		
			void initialize();
			void update();
			void render();

			void initializeBackground();
			void setBackgroundScale();

			void initializeButton();
			bool loadFromTexture();
			void setButtonSprite();

			void scaleAllButton();
			void setButtonScale(sf::Sprite* button_to_scale);
			void positionButton();


			void processButtonInput();
			bool buttonClick(sf::Sprite* button_sprite, sf::Vector2f mouse_position);

		private:

			const float button_width = 400.f;
			const float button_height = 140.f;
			const sf::String  background_texture_path;
			const sf::String play_button_path;
			const sf::String instruction_button_path;
			const sf::String quit_button_path;
			sf::RenderWindow* game_window;
			sf::Texture background_texture;
			sf::Texture play_button_texture;
			sf::Texture instruction_button_texture;
			sf::Texture quit_button_texture;
			sf::Sprite background_sprite;
			sf::Sprite play_button_sprite;
			sf::Sprite instruction_button_sprite;
			sf::Sprite quit_button_sprite;

			sf::Vector2f button_position;
		};
	}

}

