#include "../../Header/Enemy/EnemyController.h"
#pragma once

namespace Enemy
{
	namespace Controller
	{
		class ZapperController :public EnemyController
		{
		public:
			ZapperController(EnemyType type);
			~ZapperController();

			void initialize() override;
			void fireBullet() override;

		private:
			float vertical_travel_distance = 100.f;
			void move() override;
			void moveLeft();
			void moveRight();
			void moveDown();
		};
	}

}