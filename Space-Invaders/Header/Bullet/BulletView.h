#pragma once
#include <SFML/Graphics.hpp>


namespace Bullet 
{
	enum class BulletType;
	class BulletController;

	class  BulletView
	{
	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

	private:
		const float bullet_height = 18.f;
		const float bullet_width = 18.f;

		sf::Texture bullet_texture;
		sf::Sprite bullet_sprite;

		sf::RenderWindow* game_window;

		BulletController* bullet_controller;

		void initializingSprite(BulletType type);
		void scalingSprite();
	};

}

