#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"
namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        sf::RenderWindow* game_window;
        sf::Texture powerup_texture;
        sf::Sprite powerup_sprite;

        PowerupController* powerup_controller;
        UI::UIElement::ImageView* powerup_image;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetPowerupTexturePath();

        void Destroy();

    public:
        PowerupView();
        ~PowerupView();

        void Initialize(PowerupController* controller);
        void Update();
        void Render();
    };
}
