#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode(1280, 720);

    // Create a window object with specific dimensions, title, and default style (includes close, minimize, and maximize buttons)
    sf::RenderWindow window(videoMode, "Game Window with Standard Decorations", sf::Style::Default);

    // Set frame rate limit
    window.setFramerateLimit(60);

    // Configure window position
    window.setPosition(sf::Vector2i(100, 100));

    // Define the background color
    sf::Color backgroundColor(100, 150, 250); // A light blue color

    // Main loop that continues until the window is closed
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for key press events
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close(); // Close window on Escape key press
            }
        }

        // Clear screen with the defined background color
        window.clear(backgroundColor);

        // Update the window
        window.display();
    }

    return 0;
}
