#include <SFML/Graphics.hpp>
#include<iostream>
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Main\GameService.h"



/*
class Player
{

   
    int health=3;
    int playerScore = 0;
   
    sf::Vector2f position=sf::Vector2f(200.0f,100.0f);


    public:
    sf::Texture playerTexture;
    sf::Sprite player_sprite;
    int movementSpeed=5;

    void takeDamage() {};
    void move(float offsetX) 
    {
        position.x += offsetX;
    
    
    };
    void shootBullets() {};

    int GetMoveSpeed() {
        return movementSpeed;
    }
    
    sf::Vector2f getPosition() { return position; };
    


};

int main()
{

    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    sf::RenderWindow window(videoMode, "SPACE INVADERS");

    Player player;

    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.playerTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player.move(-1.0f*player.GetMoveSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player.move(1.0f * player.GetMoveSpeed());
            }
        }
        window.clear(sf::Color::Blue); // this code will set a blue background color (optional)

        player.player_sprite.setPosition(player.getPosition()); 

        window.draw(player.player_sprite);  

       
        window.display();
    }





    


    return 0;
}

*/

int main()
{
    GameService* gameService = new GameService();
    gameService->Ignite();

    while (gameService->IsGameRunning())
    {
        gameService->Update();
        gameService->Render();
    }
    
    return 0;
}