#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class ShieldController : public PowerupController
        {
        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();

            void OnCollected() override;
        };
    }
}
