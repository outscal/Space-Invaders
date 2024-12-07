#pragma once
#include <SFML/Graphics.hpp>


namespace UI {

	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const sf::String bgTexture_Path = "assets/textures/space_invaders_bg.png";
			const sf::String playButtonTexture_Path = "assets/textures/play_button.png";
			const sf::String instructionTexture_Path = "assets/textures/instructions_button.png";
			const sf::String quitButtonTexture_Path = "assets/textures/quit_button.png";


			//pointer to gameWindow
			sf::RenderWindow* gameWindow;

			//Textures and sprite variables
			sf::Sprite bgSprite;
			sf::Texture bgTexture;
			sf::Sprite playButtonSprite;
			sf::Texture playButtonTexture;
			sf::Sprite quitButtonSprite;
			sf::Texture quitButtonTexture;
			sf::Sprite instructionSprite;
			sf::Texture instructionTexture;

			const float buttonHeight = 150.0f;
			const float buttonWidth = 300.0f;

		public:

			//Constructors and Deconstructors
			MainMenuUIController();
			~MainMenuUIController();

			void initializeBGImage();
			void scaleBGImage();

			// Declare methods for initializing, setting, and positioning button sprites.
			
			void initializeButtonSprites();
			void setButtonSprites();
			void positionButtonSprites();


			void scaleAllButtons();
			void scaleButton(sf::Sprite* buttonToScale);

			//bool to check if image is loaded or not

			bool loadButtonTexturesFromFile();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

			//Lidecycle methods
			void initialize();
			void render();
			void update();
			void destroy();
		};

	}
}
