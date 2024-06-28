#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController();
            ~ZapperController();

            void initialize() override;
        };

        void ZapperController::fireBullet()
        {
            // we spawn the bullet and pass the needed parameters
            ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
                enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                Bullet::MovementDirection::DOWN);
        }
    }
}