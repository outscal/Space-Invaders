#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "header/GameService.h"




using namespace std;
using namespace sf;

class PlayerService {

private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(600.0f, 900.0f);
    float movement_speed = 0.3;
    int player_score = 0;

    const sf::String player_texture_path = "assets/textures/player_ship.png";

    sf::Texture player_texture;
    sf::Sprite player_sprite;

    sf::RenderWindow* game_window; //as always

    void initializePlayerSprite();
    void processPlayerInput() {};

public:

    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();

    
    //Public Getter & Setter methods
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    //sf::Vector2f getPosition();

    Vector2f getPlayerPosition() {
        return position;
    };

    float getMoveSpeed() {
        return movement_speed;
    };

    //New methods
    void takeDamage() {};

    //void moveLeft() { position.x -= movement_speed; };
    //void moveRight() { position.x += movement_speed;};

    void move(float offsetX);

    void shootBullets() {};

};