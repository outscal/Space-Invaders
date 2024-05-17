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
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");


    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Blue);

        // Draw your content here...
        

       

        // Display what was drawn
        window->display();
    }
    return 0;

}