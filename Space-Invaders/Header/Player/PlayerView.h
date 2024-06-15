#pragma once
#include <SFML/Graphics.hpp>
namespace Player {


    class PlayerController;
    class PlayerView
    {
    private:

        PlayerController* player_controller;
        const sf::String player_texture_path = "assets/textures/player_ship.png";
        const float player_sprite_width = 60.f;
        const float player_sprite_height = 60.f;

        sf::RenderWindow* game_window;

        sf::Texture player_texture;
        sf::Sprite player_sprite;

        void initializePlayerSprite();
        void scalePlayerSprite();

    public:
        void initialize(PlayerController* controller);
        PlayerView();
        ~PlayerView();

        void initialize();
        void update();
        void render();
    };
}