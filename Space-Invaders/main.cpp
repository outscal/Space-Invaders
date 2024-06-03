
#include <SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;


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

        // Clear the window
        window->clear(sf::Color::Blue);

        // Draw your content here...

        // Display what was drawn
        window->display();
    }

    return 0;
}