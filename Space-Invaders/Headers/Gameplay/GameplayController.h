#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayView;

    class GameplayController
    {
    private:
        GameplayView* gameplay_view;

    public:
        GameplayController();
        ~GameplayController();

        void Initialize();
        void Update();
        void Render();
    };
}
