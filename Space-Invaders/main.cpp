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

    // Create a green circle
    sf::CircleShape greenCircle(50); // Radius of 50
    greenCircle.setFillColor(sf::Color::Green);
    greenCircle.setPosition(window.getSize().x / 4 - greenCircle.getRadius(), window.getSize().y / 2 - greenCircle.getRadius());

    // Create a red square
    sf::RectangleShape redSquare(sf::Vector2f(100, 100)); // 100x100 square
    redSquare.setFillColor(sf::Color::Red);
    redSquare.setPosition(window.getSize().x / 2 - redSquare.getSize().x / 2, window.getSize().y / 2 - redSquare.getSize().y / 2);

    // Create a blue triangle
    sf::ConvexShape blueTriangle;
    blueTriangle.setPointCount(3); // A triangle has 3 points
    blueTriangle.setPoint(0, sf::Vector2f(0, 100));
    blueTriangle.setPoint(1, sf::Vector2f(50, 0));
    blueTriangle.setPoint(2, sf::Vector2f(100, 100));
    blueTriangle.setFillColor(sf::Color::Blue);
    blueTriangle.setPosition(3 * window.getSize().x / 4 - 50, window.getSize().y / 2 - 50);

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

        // Draw shapes
        window.draw(greenCircle);
        window.draw(redSquare);
        window.draw(blueTriangle);

        // Update the window
        window.display();
    }

    return 0;
}
