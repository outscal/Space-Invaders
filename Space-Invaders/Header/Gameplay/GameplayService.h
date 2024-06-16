#pragma once
#include "../../Header/Gameplay/GameplayController .h"


namespace Gameplay
{
	class GameplayService
	{
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

	private:
		GameplayController* gameplay_controller;
	};

}

