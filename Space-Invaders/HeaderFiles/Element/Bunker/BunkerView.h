#pragma once
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Element/Bunker/BunkerModel.h"


namespace Element
{
	
	namespace Bunker
	{
		class BunkerController;

		class BunkerView
		{
		private:

			const float bunkerSpriteWidth = 80.0f;
			const float bunkerSpriteHeight = 80.0f;

			const sf::String bunker_texture_path = "assets/textures/bunker.png";

			BunkerController* bunkerController;
			sf::RenderWindow *gameWindow;

			void initializeBunkerSprite();
			void scaleBunkerSprite();

			sf::Sprite bunkerSprite;
			sf::Texture bunkerTexture;


		public:
			BunkerView();
			~BunkerView();
		
			void initialize(BunkerController * controller);
			void update();
			void render();
		};
	}
}

