#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace std;

class Player {
private:

    int health ;
    sf::Vector2f position;
    int player_score ;
    int movement_speed ;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    int getScore()
    {
        return player_score;
    }
    void setScore(int newScore)
    {
        player_score = newScore;
    }

    void takeDamage() 
    {
    }
    void move()
    {
    }

    void shootBullets()
    {
    }

   
};

int main()
{
    sf::VideoMode videoMode = sf::VideoMode(800,600);
    sf::RenderWindow window(videoMode, "SFML Window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);

        window.display();
    }

    return 0;
}