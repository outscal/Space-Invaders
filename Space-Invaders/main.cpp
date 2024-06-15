#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <Windows.h>
#include <string>


int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    window.setFramerateLimit(60);

    window.setPosition(sf::Vector2i(100, 100));

    //Creating a game loop to keep window from closing on its own
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::White);

        // Display whatever you draw
        window.display();
    }

    return 0;

}