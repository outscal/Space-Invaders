#pragma once
#include <SFML/Graphics.hpp> 

namespace Gameplay
{
	class GameplayView {

	private:
		// To draw it, you need a background texture, background sprite, the game window, the path to the background image file

		sf::Texture backgroundTexture;
		sf::Sprite backgroundSprite;
		sf::RenderWindow *gameWindow;
		const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";

	public:

		GameplayView();
		~GameplayView();

		void initializeBackgroundSprite();
		void scaleBackgroundSprite();
		void initialize();
		void update();
		void render();

	};
}