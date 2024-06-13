#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"

namespace Enemy
{   
    //Forward Declarations
    class EnemyController;
    enum class EnemyType;

    class EnemyView
    {
    private:
        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;
        UI::UIElement::ImageView* enemy_image;

        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetEnemyTexturePath();

        void Destroy();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();
    };
}