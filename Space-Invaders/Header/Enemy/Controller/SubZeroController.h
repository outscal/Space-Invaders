#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float movement_speed = 150.f; // Arbitrary default value for movement speed
            float vertical_movement_speed = 100.f; // Arbitrary default value for vertical movement speed

            void move() override; // Override the base move method
            void moveDown();      // Method to specify downward movement

        public:
            SubzeroController();  // Constructor
            ~SubzeroController(); // Destructor

            void initialize() override; // Override the base initialize method
        };
    }
}
