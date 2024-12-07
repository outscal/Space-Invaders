#pragma once
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{
		class ThunderSnake : public EnemyController
		{
		private:
			float horizontalMovementSpeed = 300.0f;
			float verticalMovementSpeed = 20.0f;
			void move() override;
			void moveRightDiagonal();
			void moveLeftDiagonal();
		public:

			ThunderSnake(EnemyType setType);
			~ThunderSnake() override;

			void initialize() override;
			

		};
	}
}
