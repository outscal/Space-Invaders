#include<iostream>
#include<SFML/Graphics.hpp>

class Player {

};





int main()
{
    //Difining the video mode dimensions
    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    
    // creating a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window ");

    while (window.isOpen())
    {
    sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
        }

        // Clear the  window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();









    }


    





    return 0;
}