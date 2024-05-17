#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Black);

        // Draw your content here...
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(300, 450); // Set position
        window->draw(circle);

        sf::CircleShape greenCircle(50); // Radius 50
        greenCircle.setFillColor(sf::Color::Green);
        greenCircle.setPosition(0, 0); // Set position
        window->draw(greenCircle);

        sf::RectangleShape redRectangle; // Radius 50
        redRectangle.setSize(sf::Vector2f(100, 100));
        redRectangle.setFillColor(sf::Color::Red);
        redRectangle.setPosition(110, 0);
        window->draw(redRectangle);

        sf::CircleShape blueTraingle(50); // Radius 50
        blueTraingle.setFillColor(sf::Color::Blue);
        blueTraingle.setPosition(210, 0); // Set position
        blueTraingle.setPointCount(3);
        window->draw(blueTraingle);


        sf::Texture outscalTexture;
        outscalTexture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite sprite;
        sprite.setTexture(outscalTexture);
        sprite.setPosition(200, 100);
        sprite.setRotation(45);
        sprite.setScale(0.75, 0.75);

        window->draw(sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is awesome!", font, 50);
        text.setFillColor(sf::Color::White);
        text.setPosition(0, 300);
        text.setScale(0.5, 0.5);
        window->draw(text);

        // Display what was drawn
        window->display();
    }
    return 0;

}