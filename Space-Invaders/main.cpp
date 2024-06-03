#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Black);

        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 400); // Set position
        window->draw(circle);

        // Draw a Red Square
        sf::RectangleShape rectangle(sf::Vector2f(40, 40)); // Radius is 80, has 4 points
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(400, 300); // Set position
        window->draw(rectangle);
       
        // Draw a triangle
        sf::CircleShape triangle(80, 3); // Radius 50
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(10, 200); // Set position
        window->draw(triangle);

        // Display what was drawn
        window->display();
    }

    return 0;
}
