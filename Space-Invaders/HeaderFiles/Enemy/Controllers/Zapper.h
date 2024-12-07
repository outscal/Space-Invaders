#pragma once
#include "../../HeaderFiles/Enemy/EnemyController.h"
namespace Enemy
{
	namespace Controllers
	{

		class Zapper : public EnemyController
		{
		private:

			float verticalTravelDistance = 100.0f;
			void moveLeft();
			void moveRight();
			void moveDown();
			void move() override;
		public:
			Zapper(EnemyType setType);
			~Zapper() override;

			void initialize() override;

		
		};



	}

		
}