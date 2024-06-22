#pragma once
#include <SFML/Graphics.hpp>

namespace PowerUp
{
	class PowerupController;
	enum class PowerType;
	class PowerupView
	{
	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();

		void initialSprite(PowerType type);
		void scaleSprite();

	private:
		PowerupController* power_controller;
		const float powerup_height = 30.f;
		const float powerup_width = 30.f;

		sf::Texture powerup_texture;
		sf::Sprite powerup_sprite;

		sf::RenderWindow* game_window;
		
	};

}

