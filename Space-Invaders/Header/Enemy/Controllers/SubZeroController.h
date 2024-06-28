#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;

            void move() override;
            void moveDown();

        public:
            SubzeroController();
            ~SubzeroController();

            void initialize() override;
        };

        void SubZeroController::fireBullet()
        {
            // we spawn the bullet and pass the needed parameters
            ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
                enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                Bullet::MovementDirection::DOWN);
        }
    }
}
