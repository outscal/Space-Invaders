#pragma once
#include "../../Header/Power/PowerupController.h"

namespace PowerUp
{
	namespace Controller
	{
		class TripleLaserController :public PowerupController
		{
		public:
			TripleLaserController(PowerType type);
			virtual ~TripleLaserController();

			void onCollected() override;


		private:

		};
	}
}



