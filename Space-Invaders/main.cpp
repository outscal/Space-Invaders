
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(1080, 720));


    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "Resizable Window", sf::Style::Resize); //Change window size :

    //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen); //Enable fullscreen mode:


   // window.setFramerateLimit(60); //Set frame rate limit:

  //  window.setPosition(sf::Vector2i(100, 100)); //Configure window position:



    // Game loop to keep the window open
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 50);
        text.setFillColor(sf::Color::White);

        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);
       
        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(170, 400); // Set position

        // Draw a rectangle
        sf::RectangleShape retangle(sf::Vector2f(100, 100)); // height and width
        retangle.setFillColor(sf::Color::Red);
        retangle.setPosition(370, 400); // Set position

        // Draw triangle
        sf::ConvexShape triangle(3); // Triângulo com 3 vértices
        triangle.setPoint(0, sf::Vector2f(50, 0));
        triangle.setPoint(1, sf::Vector2f(0, 100));
        triangle.setPoint(2, sf::Vector2f(100, 100));
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(570, 400); // Define a posição

        //Draw Sprite
        outscal_sprite.setPosition(200, 100); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor


        // Clear the window
        window->clear(sf::Color::Magenta);
        
        // Draw your content here...

        window->draw(circle);

		window->draw(retangle);

		window->draw(triangle);

        window->draw(outscal_sprite);

        window->draw(text);


        // Display what was drawn
        window->display();
    }

    return 0;
}