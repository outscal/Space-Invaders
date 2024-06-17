#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int player_score = 0;
    int movement_speed = 5;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    int getScore() {
        return player_score;
    }

    void setScore(int newScore) {
        player_score = newScore;
    }

    sf::Vector2f getPosition() {
        return position;
    }

    void setPosition(sf::Vector2f newPosition) {
        position = newPosition;
    }

    void takeDamage() {
        if (health > 0) {
            health--;
        }
    }

    void move(sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Left) {
            position.x -= movement_speed;
        }
        else if (key == sf::Keyboard::Right) {
            position.x += movement_speed;
        }
    }

    void shootBullets() {
        // Implement shooting logic here
    }
};

int main() {
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080); // Define the video mode (dimensions)
    sf::RenderWindow window(videoMode, "SFML Window"); // Create a window object

    Player player; // Create the player object

    if (!player.player_texture.loadFromFile("assets/textures/player_ship.png")) {
        std::cerr << "Error loading player ship texture" << std::endl;
        return -1;
    }

    player.player_sprite.setTexture(player.player_texture); // Set the player sprite texture

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(sf::Keyboard::Left);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(sf::Keyboard::Right);
        }

        // Clear the window
        window.clear(sf::Color::Blue); // this code will set a blue background color (optional)

        player.player_sprite.setPosition(player.getPosition()); // Set the position of the player sprite

        window.draw(player.player_sprite); // Draw the player sprite

        window.display(); // Display what was drawn
    }

    return 0;
}
