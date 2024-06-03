#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Projectile\IProjectile.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletConfig.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;
    enum class BulletType;

    class BulletController : public Projectile::IProjectile
    {
    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;

        void UpdateProjectilePosition() override;
        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType type);
        virtual ~BulletController() override;
        void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();
    };
}
