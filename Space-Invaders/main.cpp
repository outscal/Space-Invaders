#include <SFML/Graphics.hpp>


int main()
{


    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));


    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");
    


    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
          

            if (event.type == sf::Event::Closed)
                window->close();
        }


        window->clear(sf::Color::Blue);


        sf::CircleShape circle(65);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(150, 150);
        window->draw(circle);

        sf::RectangleShape rectangle(sf::Vector2f(80.0f, 80.0f));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(400, 300);
        window->draw(rectangle);

        sf::ConvexShape triangle(3);
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(0, 30));
        triangle.setPoint(1, sf::Vector2f(0, 120));
        triangle.setPoint(2, sf::Vector2f(90, 75));
        triangle.setFillColor(sf::Color::Magenta);
        triangle.setPosition(550, 150);
        window->draw(triangle);

        sf::Texture texture;
        texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(texture);
        outscal_sprite.setPosition(50,300);
        outscal_sprite.setRotation(45);
        outscal_sprite.setScale(0.5,0.5);
        window->draw(outscal_sprite);

        sf::Font font;
        if (!font.loadFromFile("assets/fonts/OpenSans.ttf"))
        {

        }

        sf::Text text;
        text.setFont(font);
        text.setString("I love SFML");
        text.setCharacterSize(44);
        text.setFillColor(sf::Color::White);
        text.setPosition(600,500);
        text.setRotation(305);
        window->draw(text);



        window->display();
    }


    return 0;
}