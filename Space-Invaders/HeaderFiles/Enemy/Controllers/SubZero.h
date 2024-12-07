#pragma once
#include "../../HeaderFiles/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controllers
	{

		class SubZero : public EnemyController
		{
		private:
			float movementSpeed = 100.0f;
			void move() override;
			void moveDown();

		public:

			SubZero(EnemyType setType);
			~SubZero() override;

			void initialize() override;
		


		};

	}
}