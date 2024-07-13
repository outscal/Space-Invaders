#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Black);

        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(100, 200); // Set position
        window.draw(circle);

        sf::RectangleShape rectangle(sf::Vector2f(100, 100));
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setPosition(300, 200);
            window.draw(rectangle);

            sf::CircleShape triangle(80, 3);
            triangle.setFillColor(sf::Color::Blue);
            triangle.setPosition(500, 200);
            window.draw(triangle);


            sf::Texture outscal_texture;
            outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

            sf::Sprite outscal_sprite;
            outscal_sprite.setTexture(outscal_texture);
            outscal_sprite.setPosition(400, 300);
            outscal_sprite.setRotation(45);
            outscal_sprite.setScale(0.5, 0.5);
            window.draw(outscal_sprite);

            sf::Font font;
            font.loadFromFile("assets/fonts/OpenSans.ttf");
            sf::Text text("SFML is Awesome", font, 50);
            text.setFillColor(sf::Color::White);
            window.draw(text);

        // Display whatever you draw
        window.display();

        window.setFramerateLimit(60);

        window.setPosition(sf::Vector2i(200, 100));
    }

    return 0;
}