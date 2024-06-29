#pragma once
#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TripleLaserController : public PowerupController
        {
        protected:
            void applyPowerup() override;

        public:
            TripleLaserController(PowerupType type);
            virtual ~TripleLaserController();
        };
    }
}