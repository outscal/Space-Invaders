#pragma once

namespace Enemy
{
    enum class EnemyType
    {
        ZAPPER, 
        SUBZER,
        UFO,
        THUNDER_SNAKE,
    };

    enum class EnemyState
    {
        PATROLLING,
        ATTACK,
        DEAD,
    };

    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
    };
}