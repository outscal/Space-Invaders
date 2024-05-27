#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const sf::String enemy_texture_path = 
        "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/zapper.png";

        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;

        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        void InitializeEnemySprite();
        void ScaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();
    };
}