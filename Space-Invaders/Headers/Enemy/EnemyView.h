#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{   
    //Forward Declarations
    class EnemyController;
    enum class EnemyType;

    class EnemyView
    {
    private:
        const sf::String zapper_texture_path = 
        "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/zapper.png";
        const sf::String subzero_texture_path =
            "C:/Users/avnis/OneDrive/Desktop/Avnish Space Invaders/Space-Invaders-SFML/Space-Invaders/assets/textures/subzero.png";

        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;

        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        void InitializeEnemySprite(EnemyType type);
        void ScaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();
    };
}