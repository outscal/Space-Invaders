#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
    enum class BulletType;
    enum class MovementDirection;

    class BulletModel
    {
    private:
        float movement_speed = 300.f;
        sf::Vector2f bullet_position;

        BulletType bullet_type;
        MovementDirection movement_direction;

    public:

        BulletModel(BulletType type);
        ~BulletModel();

        void Initialize(sf::Vector2f position, MovementDirection direction);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f position);

        BulletType GetBulletType();
        void SetBulletType(BulletType type);

        MovementDirection GetMovementDirection();
        void SetMovementDirection(MovementDirection direction);

        float GetMovementSpeed();
        void SetMovementSpeed(float speed);
    };
}