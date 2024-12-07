#pragma once

namespace Enemy
{
	enum class EnemyState
	{
		ALIVE,
		DEAD,
		PATROLLING
	};

	enum class EnemyType
	{
		ZAPPER,  
		SUBZERO, 
		//UFO,
		THUNDERSNAKE
	};

	enum class MovementDirection
	{
		DOWN,
		UP,
		RIGHT,
		LEFT
	};

}