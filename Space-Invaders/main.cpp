#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{   //Properties
    public:
    sf::Texture ship_Texture;
    sf::Sprite ship_Sprite;
    int health;
    int movementSpeed = 10;
    sf::Vector2f position;//set position in window

    
    void TakeDamage(){}
    void Move(){}
    void ShootBullets(){}

};

int main() 
{

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    //Player Object
    Player playerObj;
    playerObj.ship_Texture.loadFromFile("C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/player_ship.png");
    playerObj.ship_Sprite.setTexture(playerObj.ship_Texture);
    //Enable fullscreen mode:
    //sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Fullscreen Window",sf::Style::Fullscreen);


    // Game loop to keep the window open
    while (window->isOpen()) 
    {
        //Set Framerate limit
        window->setFramerateLimit(60);

        //Set window position on screen
        //window->setPosition(sf::Vector2i(100, 100));

        //Event object
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }


        //Handle Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //call move here after player obj
            playerObj.Move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //call move here after player obj
            playerObj.Move();
        }
        
        //Clear Window
        window->clear(sf::Color::Blue);

        playerObj.ship_Sprite.setPosition(playerObj.position); // Set the position of the player sprite

        window->draw(playerObj.ship_Sprite);    // Draw the player sprite

        window->display(); // Display what was drawn
    } //while loop end.
   

    
}