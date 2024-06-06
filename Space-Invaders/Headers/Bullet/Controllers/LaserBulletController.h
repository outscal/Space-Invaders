#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class LaserBulletController : public BulletController
        {
        public:
            LaserBulletController(BulletType type, Entity::EntityType owner_type);
            ~LaserBulletController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}
