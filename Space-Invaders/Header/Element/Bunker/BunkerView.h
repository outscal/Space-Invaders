#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerController.h"
namespace Element
{
	namespace Bunker
	{
		class BunkerView
		{
		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();

			void initializeSprite();
			void scaleSprite();

		private:
			const float bunker_height = 50.f;
			const float bunker_width = 50.f;

			sf::String bunker_texture_path = "assets/textures/bunker.png";
			sf::Texture bunker_texture;
			sf::Sprite bunker_sprite;

			BunkerController* bunker_controller;
			sf::RenderWindow* game_window;

		};

	}
}

