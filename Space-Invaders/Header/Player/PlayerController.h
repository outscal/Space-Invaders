#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
    enum class PlayerState;

    class PlayerView;
    class PlayerModel;

    class PlayerController
    {
    private:
        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();
        void fireBullet();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

    };

}