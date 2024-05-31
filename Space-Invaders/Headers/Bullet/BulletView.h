#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"

namespace Bullet
{
    class BulletController;
    enum class BulletType;

    class BulletView
    {
    private:
        const float bullet_sprite_width = 18.f;
        const float bullet_sprite_height = 18.f;

        sf::RenderWindow* game_window;
        sf::Texture bullet_texture;
        sf::Sprite bullet_sprite;

        BulletController* bullet_controller;
        UI::UIElement::ImageView* bullet_image;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetBulletTexturePath();

        void Destroy();
    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* controller);
        void Update();
        void Render();
    };
}
