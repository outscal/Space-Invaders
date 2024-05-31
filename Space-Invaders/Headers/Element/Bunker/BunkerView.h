#pragma once
#include <SFML/Graphics.hpp>
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView
        {
        private:
            const float bunker_sprite_width = 80.f;
            const float bunker_sprite_height = 80.f;

            BunkerController* bunker_controller;
            UI::UIElement::ImageView* bunker_image;

            sf::RenderWindow* game_window;
            sf::Texture bunker_texture;
            sf::Sprite bunker_sprite;

            void CreateUIElements();
            void InitializeImage();
            sf::String GetBunkerTexturePath();

            void Destroy();

        public:
            BunkerView();
            ~BunkerView();

            void Initialize(BunkerController* controller);
            void Update();
            void Render();
        };
    }
}
