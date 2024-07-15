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

	   void setScore(int newScore)
	   {
		   player_Score = newScore;
	   };

	   void takeDamage()
	   {

	   };

	   void move()
	   {

	   };

	   void shootBullets()
	   {

	   };
};

int main() 
{
	
}
