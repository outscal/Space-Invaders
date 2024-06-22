#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Power/PowerConfig.h"

namespace Enemy
{
	namespace Controller
	{
		//enum class MovementDirection;
		class UFOController:public EnemyController
		{
		public:
			UFOController(EnemyType type);
			virtual ~UFOController();

			void initialize() override;

		private:
			float speed = 20.f;
			void move() override;
			void moveLeft();
			void moveRight();
			void fireBullet() override;

			PowerUp::PowerType getRandomPower();

			
			
		};
	}


}

