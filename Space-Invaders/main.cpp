
#include <SFML/Graphics.hpp>

int main()
{
 

    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    sf::RenderWindow*window = new sf::RenderWindow(videoMode, "My SFML Project");

    //Game Loop
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::Black);

        //Draw
        //Text
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awsome!!", font, 50);
        text.setPosition(200, 100);
        text.setFillColor(sf::Color::White);
        window->draw(text);

        //Texture
        sf::Texture texture;
        texture.loadFromFile("assets/textures/player_ship.png");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(400, 300);
        sprite.setRotation(45);
        sprite.setScale(1, 1);
        window->draw(sprite);

   
        ////Circle
        //sf::CircleShape greensCircle(50);
        //greensCircle.setFillColor(sf::Color::Green);
        //greensCircle.setPosition(200, 300);
        //window->draw(greensCircle);


        ////Rectangle
        //sf::RectangleShape redSquare(sf::Vector2f(200.f,200.f));
        //redSquare.setFillColor(sf::Color::Red);
        //redSquare.setPosition(400, 300);
        //window->draw(redSquare);


        ////Blue Triangle
        //sf::ConvexShape blueTriangle;
        //blueTriangle.setPointCount(3);
        //blueTriangle.setPoint(0,sf::Vector2f(200,50));
        //blueTriangle.setPoint(1, sf::Vector2f(300, 200));
        //blueTriangle.setPoint(2, sf::Vector2f(100, 200));
        //blueTriangle.setFillColor(sf::Color::Blue);
        //window->draw(blueTriangle);

        window->display();
    }

    return 0;
}