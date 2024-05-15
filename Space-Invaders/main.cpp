#include <SFML/Graphics.hpp>

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
        //window->setFramerateLimit(60);

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

        // Draw your content here...

        // Display what was drawn
        window->display();
    }

    return 0;
}