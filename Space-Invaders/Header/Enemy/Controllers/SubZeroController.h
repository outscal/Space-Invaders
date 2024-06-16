#pragma once
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy
{
	namespace Controller
	{
		class SubZeroController :public EnemyController
		{
		public:
			SubZeroController(EnemyType type);
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
	
}