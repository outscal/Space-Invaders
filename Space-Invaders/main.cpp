
#include <SFML/Graphics.hpp>


//Player Class
class Player
{
private:
    int playerScore = 0;
    int health = 3;
    int movementSpeed = 5;
    sf::Vector2f Position = sf::Vector2f(200.0f, 100.0f);

public:

    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
    int getScore()
    {
        return playerScore;
    }

    void setScore(int newScore) 
    {
        playerScore = newScore;
    }

    void setPosition(float)
    {
        Position = Position;
    }

    float getPosition()
    {
        
    }

    void takeDamage(){}
    void move(){}
    void shoot(){}

};



int main()
{
    sf::VideoMode videoMode = sf::VideoMode(800, 600); 

    sf::RenderWindow window(videoMode, "SFML Window"); 

    Player player; 

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture); 
    //player.setPosition(200, 100);

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
            player.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            player.move();
        }
        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(200.0f, 100.0f);

        window.draw(player.player_sprite);

        window.display();

    } 

    return 0;
}