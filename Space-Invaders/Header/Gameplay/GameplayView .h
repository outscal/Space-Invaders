#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/UIElement/ImageView.h"


namespace Gameplay
{
	class GameplayView
	{
	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

	/*	void initializeBackgroundImage();
		void setBackgroundScale();*/

	private:
		const sf::Vector2f background_position = sf::Vector2f(960.f, 540.f);
		const sf::String background_texture_path;
		sf::RenderWindow* game_window;
		sf::Texture background_texture;
		sf::Sprite background_sprite;


		UI::UIElement::ImageView* gameplayimage_view;

		void createUIElement();
		void initilizeImage();
		sf::String getGameplayTexturePath();
		void destroy();
	};

}

