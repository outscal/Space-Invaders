#pragma once
#include "../../Header/Gameplay/GameplayView .h"

namespace Gameplay
{
	class GameplayController
	{
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

	private:
		GameplayView* gameplay_view;
	};

}

