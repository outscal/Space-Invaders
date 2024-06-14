#include "../../Header/Enemy/EnemyController.h"
#pragma once

namespace Enemy
{
	class ZapperController:public EnemyController
	{
	public:
		ZapperController();
		~ZapperController();

		void initialize() override;
	
	private:
		float vertical_travel_distance = 100.f;
		void move() override;
		void moveLeft();
		void moveRight();
		void moveDown();
	};
}