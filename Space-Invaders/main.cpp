#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "MY SFML Window");

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear(sf::Color::Blue);

        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(50, 100);
        window->draw(circle);

        sf::RectangleShape(rectangle);
        rectangle.setSize(sf::Vector2f(100, 100));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(300,100);
        window->draw(rectangle);

        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(90, 0));
        triangle.setPoint(1, sf::Vector2f(0, 90));
        triangle.setPoint(2, sf::Vector2f(90, 180));
        triangle.setFillColor(sf::Color::Magenta);
        triangle.setPosition(550,50);
        window->draw(triangle);

        sf::Texture texture;
        texture.loadFromFile("assets/textures/outscal_logo.png");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(100,300);
        sprite.setRotation(45);
        sprite.setScale(0.5,0.5);
        window->draw(sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");

        sf::Text text;
        text.setFont(font);
        text.setString("I love SFML");
        text.setCharacterSize(46);
        text.setFillColor(sf::Color::White);
        text.setPosition(550,525);
        text.setRotation(295);
        window->draw(text);
     
        window->display();
    }
    return 0;
}