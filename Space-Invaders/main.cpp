#include <SFML/Graphics.hpp>
int main()
{
    sf::VideoMode vMode = sf::VideoMode(800, 600);//this is to create the length and widht of the window

    sf::RenderWindow rWindow(vMode, "SFML Window");//this is to create the window itself
    //rWindow.clear(sf::Color::Red);
    //sf::RenderWindow rWindow(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);//for fullscreen

    //rWindow.setFramerateLimit(60);//frame rate limiting
    //window.setPosition(sf::Vector2i(100, 100));// to set the position of the window
    
    while (rWindow.isOpen())
    {
        sf::Event event;
        while (rWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                rWindow.close();
        }

        rWindow.clear(sf::Color::Black);

        /*
        //Drawing a circle
        sf::CircleShape circleObject(50);
        circleObject.setFillColor(sf::Color::Green);
        //circleObject.setPosition(400,300);//using pixel value
        //circleObject.setPosition(rWindow.getSize().x, rWindow.getSize().y);//bottom right
        circleObject.setPosition(0, 0);
        rWindow.draw(circleObject);
        */

        /*
        sf::RectangleShape rectangleObject;
        rectangleObject.setFillColor(sf::Color::Red);
        rectangleObject.setSize(sf::Vector2f(50,50));
        rectangleObject.setPosition(400, 400);
        rWindow.draw(rectangleObject);
        */

        /*
        sf::ConvexShape triangleObject;
        triangleObject.setFillColor(sf::Color::Blue);
        triangleObject.setPointCount(3);
        triangleObject.setPosition(200, 400);
        triangleObject.setPoint(0, sf::Vector2f(100, 100));
        triangleObject.setPoint(1, sf::Vector2f(0, 100));
        triangleObject.setPoint(2, sf::Vector2f(100, 0));
        rWindow.draw(triangleObject);
        */

        sf::Texture outscal_logo;//Texture creation
        outscal_logo.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite logo_sprite;//sprite Creation
        logo_sprite.setTexture(outscal_logo);
        logo_sprite.setScale(0.2, 0.2);
        logo_sprite.setRotation(45);
        logo_sprite.setPosition(400, 400);
        rWindow.draw(logo_sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 13);
        text.setFillColor(sf::Color::Red);
        rWindow.draw(text);


        rWindow.display();
    }
}