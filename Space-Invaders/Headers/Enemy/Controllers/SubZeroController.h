#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;

            void Move() override;
            void MoveDown();

        public:
            SubzeroController();
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void Initialize() override;
        };
    }
}

