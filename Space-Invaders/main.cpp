
#include <SFML/Graphics.hpp>


//Player Class
class Player
{
private:
    int playerScore = 0;
    int health = 3;
    int movementSpeed = 5;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);

public:

    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
    int getScore()
    {
        return playerScore;
    }

    void takeDamage(){}
    void move(){}
    void shoot(){}

};



int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();


   




    }

    return 0;
}