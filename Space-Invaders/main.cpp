#include <iostream>
#include <SFML/Graphics.hpp>

//Creating empty player class below
class Player {
    private: // private access modifier
        //private properties
        int health = 3;
        sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
        int movement_speed = 5;
        int player_score = 0;

    public: // public access modifier 
        //public Properties
        sf::Texture player_texture;
        sf::Sprite player_sprite; 

    //Public Getter & Setter methods
        int getScore() {
            return player_score;
        }
        void setScore(int newScore) {
            player_score = newScore;
        }
        void takeDamage() {};

        void move(float offsetX) {
            position.x += offsetX;
        }

        int getMoveSpeed() {
            return movement_speed;
        }

        sf::Vector2f getPosition() {
            return position;
        }

        void shootBullets() {}
};

    int main() {

        sf::VideoMode videoMode = sf::VideoMode(800, 600); // Define the video mode (dimensions)

        sf::RenderWindow window(videoMode, "SFML Window");  // Create a window object

        Player player;  // Create the player object

        player.player_texture.loadFromFile("assets/textures/player_ship.png"); // Load the player ship texture

        player.player_sprite.setTexture(player.player_texture);  // Set the player sprite variable 

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // Check for window closure
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Handle keyboard input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.move(-1.0f*player.getMoveSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.move(-1.0f*player.getMoveSpeed());
            }

            // Clear the window
            window.clear(sf::Color::Blue); // this code will set a blue background color (optional)

            player.player_sprite.setPosition(player.getPosition()); // Set the position of the player sprite

            window.draw(player.player_sprite);    // Draw the player sprite

            window.display(); // Display what was drawn

        } // end while loop

        return 0;
    }
