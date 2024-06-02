#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include<iostream>
using namespace std;

class Player {
private:

    int health ;
    
    int player_score ;
    int movement_speed ;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    sf::Vector2f player_position ;
    float position;

    int getScore()
    {
        return player_score;
    }
    void setScore(int newScore)
    {
        player_score = newScore;
    }
    float getPosition()
    {
        inline sf::Vector2f::Vector2(float X,float Y);
    }
    void setPosition()
    {
        position = getPosition();
    }
    void takeDamage() 
    {
    }
    void move()
    {
        cout << "is moving" << endl;
    }

    void shootBullets()
    {
    }

   
};

int main()
{
    //window
    sf::VideoMode videoMode = sf::VideoMode(800,600);
    sf::RenderWindow window(videoMode, "SFML Window");

    //player
    Player player;
    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);

    // loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move();
        }

        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(400.0f,200.0f);
        window.draw(player.player_sprite);

        window.display();
    }

    return 0;
}