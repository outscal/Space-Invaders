#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy {
	class EnemyController;
	enum class EnemyType;
	class EnemyView
	
	{
	private:

		const sf::String subzero_texture_path = "assets/textures/subzero.png";
		const sf::String zapper_texture_path = "assets/textures/zapper.png";
		const sf::String thundersnake_texture_path = "assets/textures/thunder_snake.png";
		const float enemySpriteWidth = 60.f;
		const float enemySpriteHeight = 60.f;

		sf::RenderWindow* gameWindow;
		sf::Texture enemyTexture;
		sf::Sprite enemySprite;

		EnemyController* enemyController;

		void initializeEnemySprites(EnemyType setType);
		void scaleEnemySprites();


	public:
		EnemyView();
		~EnemyView();

		//Lifecycle
		
		void initialize(EnemyController * controller);
		void update();
		void render();

	};

}

