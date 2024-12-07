
#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/gameservice.h"
using namespace std;
using namespace sf;

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);
    sf::RenderWindow window(videoMode, "SFML Window");



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f * player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f * player.getMoveSpeed());

        }
        window.clear(sf::Color::Green);
        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);
        window.display();
    }
        gameService game_service; 
        game_service.ignite();

        // Clear the window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();
    }

>>>>>>> Stashed changes
    return 0;
}