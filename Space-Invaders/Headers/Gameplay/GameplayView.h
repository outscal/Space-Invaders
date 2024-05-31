#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayView
    {
    private:
        sf::RenderWindow* game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        void InitializeBackgroundSprite();
        void ScaleBackgroundSprite();

    public:
        GameplayView();
        ~GameplayView();

        void Initialize();
        void Update();
        void Render();
    };
}