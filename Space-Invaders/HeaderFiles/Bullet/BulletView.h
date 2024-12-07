#pragma once
#include <SFML/Graphics.hpp>



namespace Bullet
{
	enum class BulletType;
	class BulletController;

	class BulletView
	{

	private:

		sf::Sprite bulletSprite;
		sf::Texture bulletTexture;

		sf::RenderWindow* window;

		const float bulletSpriteHeight = 18.0f;
		const float bulletSpriteWidth = 18.0f;

		BulletController* bulletController;

		void initializeBulletSprite(BulletType type);
		void scaleBulletSprite();

	public:

		BulletView();
		~BulletView();

		void initialize(BulletController* controller);

		void update();

		void render();





	};
}