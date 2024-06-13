#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"

namespace Player
{
	class PlayerView
	{
	private:
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;

		sf::RenderWindow* game_window;

		sf::Texture player_texture;
		sf::Sprite player_sprite;

		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		void CreateUIElements();
		void InitializeImage();
		sf::String GetPlayerTexturePath();

		void Destroy();
	public:
		PlayerView();
		~PlayerView();

		//Lifecycle Methods 
		void Initialize(PlayerController* controller);
		void Update();
		void Render();
	};
}
