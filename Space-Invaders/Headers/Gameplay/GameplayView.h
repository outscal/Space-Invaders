#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"

namespace Gameplay
{
    class GameplayView
    {
    private:
        const sf::Vector2f background_position = sf::Vector2f(960.f, 540.f);
        sf::RenderWindow* game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        UI::UIElement::ImageView* background_image;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetBackgroundTexturePath();

        void Destroy();

    public:
        GameplayView();
        ~GameplayView();

        void Initialize();
        void Update();
        void Render();
    };
}