#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class RapidFireController : public PowerupController
        {
        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();

            void OnCollected() override;
        };
    }
}
