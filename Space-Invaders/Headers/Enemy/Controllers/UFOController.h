#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:

            void Move() override;
            void MoveLeft();
            void MoveRight();

            void FireBullet() override;
            Powerup::PowerupType GetRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void Initialize() override;
        };
    }
}