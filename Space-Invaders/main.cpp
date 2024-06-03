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

        //Texture and sprite
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(50, 50); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor
        window->draw(outscal_sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("Hello SFML!", font, 50);
        text.setFillColor(sf::Color::Red);
        window->draw(text);


        // Display what was drawn;
        window->display();
    }

    return 0;
}
