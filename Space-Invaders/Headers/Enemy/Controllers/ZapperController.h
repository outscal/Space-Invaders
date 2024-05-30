#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float zapper_rate_of_fire = 2.f;

            void Move() override;
            void MoveLeft();
            void MoveRight();
            void MoveDown();
            void FireBullet() override;
        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void Initialize() override;
        };
    }
}