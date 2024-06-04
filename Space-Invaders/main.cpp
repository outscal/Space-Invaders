
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));


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
       
        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(150, 250); // Set position

        // Draw a rectangle
        sf::RectangleShape retangle(sf::Vector2f(100, 100)); // height and width
        retangle.setFillColor(sf::Color::Red);
        retangle.setPosition(350, 250); // Set position

        // Draw triangle
        sf::ConvexShape triangle(3); // Triângulo com 3 vértices
        triangle.setPoint(0, sf::Vector2f(50, 0));
        triangle.setPoint(1, sf::Vector2f(0, 100));
        triangle.setPoint(2, sf::Vector2f(100, 100));
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(550, 250); // Define a posição

        // Clear the window
        window->clear(sf::Color::White);
        
        // Draw your content here...

        window->draw(circle);

		window->draw(retangle);

		window->draw(triangle);


        // Display what was drawn
        window->display();
    }

    return 0;
}