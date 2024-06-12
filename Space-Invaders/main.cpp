#include <SFML/Graphics.hpp>

int main()
{

    sf::VideoMode videoMode = *(new sf::VideoMode(1280, 720));

    // Create a window object with specific dimensions and a title
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

        //Draw Circle
        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(window->getSize().x / 2 - circle.getRadius(), window->getSize().y / 2 - circle.getRadius());
        window->draw(circle);

        //Draw Rectangle
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition(0,0);
        window->draw(rectangle);


        //Draw Triangle
        sf::CircleShape triangle(80.f, 3);
        triangle.setFillColor(sf::Color::Magenta);
        triangle.setPosition(1130, 600);
        window->draw(triangle);


        //loading texture
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        //creating sprite
        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);
        outscal_sprite.setPosition(700, 100);
        outscal_sprite.setRotation(45);
        outscal_sprite.setScale(0.5, 0.5);
        
        window->draw(outscal_sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 50);
        text.setFillColor(sf::Color::White);
        text.setPosition(window->getSize().x/ 2-200, 600);

        window->draw(text);
        

        window->display();


    }

    return 0;
}