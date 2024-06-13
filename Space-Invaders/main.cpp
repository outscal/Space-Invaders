#include <SFML/Graphics.hpp>

int main() {
    // Define the video mode (dimensions)
    sf::VideoMode videoMode(1920, 1080);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "Draw some shapes");

    // Game loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw a circle
        sf::CircleShape circle(80); // Radius 60
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(900, 200); // Set position
        window.draw(circle);

        // Draw a triangle
        sf::ConvexShape triangle;
        triangle.setPointCount(3); // Define 3 points for the triangle
        triangle.setPoint(0, sf::Vector2f(0, 0));
        triangle.setPoint(1, sf::Vector2f(200, 0));
        triangle.setPoint(2, sf::Vector2f(100, 200));
        triangle.setFillColor(sf::Color::Green);
        triangle.setPosition(500, 600); // Set position
        window.draw(triangle);

        // Draw a rectangle
        sf::RectangleShape rectangle(sf::Vector2f(280, 160)); // Size 120x60
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(800, 800); // Set position
        window.draw(rectangle);

        // Draw your content here...

        // Display what was drawn
        window.display();
    }

    return 0;
}
