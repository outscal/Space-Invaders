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
            float subzero_rate_of_fire = 3.f;
            void Move() override;
            void MoveDown();
            void FireBullet() override;

        public:
            SubzeroController(EnemyType type, Entity::EntityType owner_type);
            ~SubzeroController();

            void Initialize() override;
        };
    }
}

