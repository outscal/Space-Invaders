#include <SFML/Graphics.hpp>

int main()
{

    sf::VideoMode videoMode = sf::VideoMode(1200, 800);
    sf::RenderWindow window(videoMode, "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();
    }

    return 0;
}