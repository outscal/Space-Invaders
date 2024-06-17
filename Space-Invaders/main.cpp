#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{

private:

    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:

    // Properties
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    //functions
    void move(float offsetX) {
        position.x += offsetX;
    }

    int getMoveSpeed() {
        return movement_speed;
    }

    sf::Vector2f getPosition() {
        return position;
    }

};

int main() {
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // Using default constructor
    Player player;

    // Load the player ship texture  
    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    // Set the player sprite variable to the player ship texture
    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f * player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f * player.getMoveSpeed());
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Set the position of the player sprite
        player.player_sprite.setPosition(player.getPosition());

        // Draw the player sprite
        window.draw(player.player_sprite);

        // Display what was drawn
        window.display();
    }

    return 0;
}