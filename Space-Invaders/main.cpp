#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
<<<<<<< Updated upstream
    sf::VideoMode videoMode = sf::VideoMode(1920, 1280);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");
   
=======
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);
>>>>>>> Stashed changes



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
<<<<<<< Updated upstream
        window.clear(sf::Color::Black);
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(400, 300); // Set position
        window.draw(circle);
        sf::CircleShape circle_2(20);
        circle_2.setFillColor(sf::Color::Green);
        window.draw(circle_2);
        sf::RectangleShape Rectangle(sf::Vector2f(25,25));
        Rectangle.setPosition(300, 400);
        Rectangle.setFillColor(sf::Color::Red);
        window.draw(Rectangle);
        sf::ConvexShape Triangle;
        Triangle.setPointCount(3);
        Triangle.setPoint(0, sf::Vector2f(300, 50));
        Triangle.setPoint(1, sf::Vector2f(200, 150));
        Triangle.setPoint(2, sf::Vector2f(400, 150));
        Triangle.setFillColor(sf::Color::Blue);
        window.draw(Triangle);
        sf::Texture texture;
        texture.loadFromFile("assets/textures/outscal_logo.png");
        sf::Sprite Outscal_sprite;
        Outscal_sprite.setTexture(texture);
        Outscal_sprite.setPosition(900, 200);
        Outscal_sprite.setRotation(45);
        Outscal_sprite.setScale(0.35, 0.45);
        window.draw(Outscal_sprite);
        sf::Font font;
        font.loadFromFile("assets/fonts/bubbleBobble.ttf");
        sf::Text text("My name is Shashwat Dubey.", font, 25);
        text.setFillColor(sf::Color::Yellow);
        text.setPosition(500, 800);
        window.draw(text);
        sf::Font font_2;
        font_2.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text_2("SFML is Awesome!", font, 25);
        text_2.setFillColor(sf::Color::White);
        text_2.setPosition(400, 900);
        window.draw(text_2);


        // Display whatever you draw
        window.display(); //thanks for helping 

    }
    
=======
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();
    }

>>>>>>> Stashed changes
    return 0;
}
