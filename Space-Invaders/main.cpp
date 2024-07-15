#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player 
{
	private:
		int health = 3;
		sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
		int movement_Speed = 5;
		int player_Score = 0;

   public:
	   sf :: Texture player_texture;
	   sf::Sprite player_sprite;

	   int getScore()
	   {
		   return player_Score;
	   };

	   int getMoveSpeed()
	   {
		   return movement_Speed;
	   };

	   sf::Vector2f getPosition()
	   {
		   return position;
	   };
	   void setScore(int newScore)
	   {
		   player_Score = newScore;
	   };

	   void takeDamage()
	   {

	   };

	   void move(float offsetX )
	   {
		   position.x += offsetX;
		   
	   };

	   void shootBullets()
	   {

	   };
	 
};

int main() 
{
	sf::VideoMode videomode = sf::VideoMode(800, 600);

	sf::RenderWindow window(videomode, "Player Window");

	Player player;
	player.player_texture.loadFromFile("assets/textures/player_ship.png");
	player.player_sprite.setTexture(player.player_texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-1.0f * player.getMoveSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(1.0f * player.getMoveSpeed());
		}

		window.clear(sf::Color::Black);

		player.player_sprite.setPosition(player.getPosition());

		window.draw(player.player_sprite);

		window.display();
	}
	
	
}
