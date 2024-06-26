#include <iostream>
#include <SFML/Graphics.hpp>
#include "header/GameService.h"



using namespace std;
using namespace sf;

/*
class Player {

private:
    // Private Properties
    int health = 3;
    sf::Vector2f position = sf::Vector2f(600.0f, 900.0f);
    float movement_speed = 0.3;
    int player_score = 0;

public:

    // Public Properties
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    //Public Getter & Setter methods
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    Vector2f getPosition() {
		return position;
    };

    float getMoveSpeed() {
        return movement_speed;
    };

    //New methods
    void takeDamage() {};

    //void moveLeft() { position.x -= movement_speed; };
	//void moveRight() { position.x += movement_speed;};

    void move(float offsetX) {
		position.x += offsetX;
    };




    void shootBullets() {};

};
*/


int main() {
    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
		game_service->render();
    }

   /* Player player;


    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "My Game");

	player.player_texture.loadFromFile("assets/textures/player_ship.png"); // Load the player ship texture

    player.player_sprite.setTexture(player.player_texture); // Set the player sprite variable 
    player.player_sprite.setPosition(player.getPosition());
	player.player_sprite.setScale(0.5f,0.5f);



    while (window.isOpen()) {

        sf::Event event; // create an object of the event class
        while (window.pollEvent(event)) { //check for pending events

            if (event.type == sf::Event::Closed) //check if window is being closed
                window.close();
        }

        // Handle input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left) ) {
            //player.moveLeft();
            player.move(-1.0* player.getMoveSpeed());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
            player.move(1.0f* player.getMoveSpeed());
        }


        // Clear the window
        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(player.getPosition()); // Set the position of the player sprite


        window.draw(player.player_sprite); // Draw the player sprite




        // Display whatever you draw
        window.display();

    }*/

    return 0;
}