#pragma once

namespace Enemy
{
    enum class EnemyType
    {
        ZAPPER=1,
        SUBZERO=2,
        UFO=3,
        //THUNDER_SNAKE,*/
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