#pragma once

#include <SFML/Graphics.hpp>

namespace Player 
{
	class PlayerController;


	class PlayerService
	{
	private:

		Player::PlayerController* playerController;

	public:

		PlayerService();
		~PlayerService();

		void update();
		void render();
		void initialize();


	};
}