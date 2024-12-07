#pragma once


namespace Gameplay
{
	class GameplayView;

	class GameplayController
	{
	private:
		
		GameplayView* gameplayView;

	public:

		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		
	};
}
