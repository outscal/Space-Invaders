#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
	class EnemyController;
	class EnemyView
	{
	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* enemy_controller);
		void update();
		void render();

		void initializeSprite();
		void scaleSprite();

	private:
		const sf::String enemy_texture_path = "assets/textures/zapper.png";
		const float enemy_height = 60.f;
		const float enemy_width = 60.f;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		sf::RenderWindow* game_window;
		EnemyController* enemy_controller;



	};
}


