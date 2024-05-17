#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player {
    
private:
    int playerScore;
    int health;
    int movementSpeed;
    sf::Vector2f position= sf::Vector2f(200,100);

public:

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    int getScore() {
        return playerScore;
    }

    sf::Vector2f getPosition() {
        return position;
    }

    void setScore(int newScore) {
        this->playerScore = newScore;
    }

    void takeDamage() {

    }

    void move() {

    }

    void shootBullets() {

    }
};


int main()
{
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "My SFML Window");
    Player player;
    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    player.playerSprite.setTexture(player.playerTexture);
    
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

       
      
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move();
        }
        // Clear the window
        window.clear(sf::Color::Blue);
        // Draw your content here...
        player.playerSprite.setPosition(player.getPosition());
        window.draw(player.playerSprite);

        // Display what was drawn
        window.display();
    }
    return 0;

}