#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{   //Properties
    public:
    sf::Texture ship_texture;
    sf::Sprite ship_Sprite;
    int health;
    int movementSpeed = 10;
    sf::Vector2f position;//set position in window

    
    void TakeDamage(){}
    void Move(){}
    void ShootBullets(){}

};

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(1280, 720));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    //Enable fullscreen mode:
    //sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Fullscreen Window",sf::Style::Fullscreen);


    // Game loop to keep the window open
    while (window->isOpen()) {
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
       

        // Clear the window
        window->clear(sf::Color::Blue);

        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/outscal_logo.png");
        Player player;

        std::cout << player.movementSpeed << endl;
       
        window->display();
    }

    return 0;
}