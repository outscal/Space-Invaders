#include <iostream>

#include <SFML/Graphics.hpp>

class Player {

private:

    // Private Properties
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:

    // Public Properties
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
    void move() {};
    void shootBullets() {};

};

int main() {
    // Create a Player object
    Player player;

    // Access the private variable using the public getter
    std::cout << "Player Score: " << player.getScore();

    // Modify the variable using the public setter
    player.setScore(100);

    // Access the modified variable using the public getter
    std::cout << "Player Modified Score: " << player.getScore();

    return 0;
}