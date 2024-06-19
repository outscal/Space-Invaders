#include <iostream>
#include "header/GameService.h"

/*
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
}; */

int main() {
    GameService* game_service = new GameService(); //create object

    game_service->ignite(); // "ignites"/starts the flow of our game

    //while the game is running we will update the game loop
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }
    return 0;
}

