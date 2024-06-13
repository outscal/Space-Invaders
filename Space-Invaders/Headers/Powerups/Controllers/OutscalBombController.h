#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class OutscalBombController : public PowerupController
        {
        public:
            OutscalBombController(PowerupType type);
            virtual ~OutscalBombController();

            void OnCollected() override;
        };
    }
}
