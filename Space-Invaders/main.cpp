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

       

        
        window->display();
    }


    return 0;
}