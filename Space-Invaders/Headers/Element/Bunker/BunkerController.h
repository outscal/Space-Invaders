#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerModel.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerView;

        class BunkerController
        {
        private:
            BunkerView* bunker_view;
            BunkerData bunker_data;

        public:
            BunkerController();
            ~BunkerController();

            void Initialize(BunkerData data);
            void Update();
            void Render();

            sf::Vector2f GetBunkerPosition();
        };
    }
}
