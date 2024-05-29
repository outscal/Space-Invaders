#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerController.h"
namespace Player
{
	class PlayerService
	{

	private:
		PlayerController* player_controller;
	public:
		PlayerService();
		~PlayerService();
		void Initialize();
		void Update();
		void Render();
	};
}
