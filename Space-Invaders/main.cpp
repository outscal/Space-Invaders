#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(1280, 720));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    //Enable fullscreen mode:
    //sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Fullscreen Window",sf::Style::Fullscreen);


    // Game loop to keep the window open
    while (window->isOpen()) {
        //Set Framerate limit
        //window->setFramerateLimit(60);

        //Set window position on screen
        //window->setPosition(sf::Vector2i(100, 100));



        //Event object
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }
       

        // Clear the window
        window->clear(sf::Color::White);

        // Draw your content here...
        
        // Draw a shape
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);

        sf::RectangleShape square(sf::Vector2f(100, 100));
        square.setFillColor(sf::Color::Red);

        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setFillColor(sf::Color::Blue);
        
        // Set position
        //circle.setPosition(640,360); 
        circle.setPosition(window->getSize().x / 2 - circle.getRadius(), window->getSize().y / 2 - circle.getRadius());
        
        square.setPosition(300, 300);
        
        
        triangle.setPoint(0, sf::Vector2f(100, 100));//left point
        triangle.setPoint(1, sf::Vector2f(200, 300));//bottom point
        triangle.setPoint(2, sf::Vector2f(300, 100));//right point

        //Queue for display
        window->draw(circle);
        window->draw(square);
        window->draw(triangle);

        // Display what was drawn
        window->display();
    }

    return 0;
}