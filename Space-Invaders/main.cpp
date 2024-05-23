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


        window->display();
    }


    return 0;
}