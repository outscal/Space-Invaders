#pragma once
#include <SFML/Graphics.hpp>

class PlayerService {
    private: // private access modifier
        //private properties
        int health = 3;
        sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
        int movement_speed = 5;
        int player_score = 0;

        const sf::String player_texture_path = "assets/textures/player_ship.png";

        sf::Texture player_texture;
        sf::Sprite player_sprite;

        sf::RenderWindow* game_window; // "As always"

        void initializePlayerSprite();
        void processPlayerInput();

    public: // public access modifier

        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();

        void move(float offsetX);
        int getMoveSpeed();
        sf::Vector2f getPlayerPosition();

}; 