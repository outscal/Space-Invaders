#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletController.h"
namespace Bullet
{
    namespace Controller
    {
        class TorpedoController : public BulletController
        {
        private:
            const float torpedo_movement_speed = 200.f;

        public:
            TorpedoController(BulletType type, Entity::EntityType owner_type);
            ~TorpedoController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}
