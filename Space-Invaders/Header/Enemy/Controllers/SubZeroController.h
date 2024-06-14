#pragma once
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy
{
	class SubZeroController:public EnemyController
	{
	public:
		SubZeroController();
		~SubZeroController();

		void initialize() override;
	/*	void render();
		void update();*/

		

	private:
		const float movement_speed = 100.f;
		void move() override;
		void moveDown();
	};
}