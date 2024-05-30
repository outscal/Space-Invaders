#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerView* player_view;
		PlayerModel* player_model;
		void ProcessPlayerInput();
		void MoveRight();
		void MoveLeft();
		void FireBullet();
	public:
		PlayerController();
		~PlayerController();
		void Initialize();
		void Update();
		void Render();
		sf::Vector2f GetPlayerPosition();
	};
}
