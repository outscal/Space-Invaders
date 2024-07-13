#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TrippleLaserController : public PowerupController
        {
        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();

            void OnCollected() override;
        };
    }
}

