#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Entity\EntityConfig.h"

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
		PlayerController(Entity::EntityType owner_type);
		~PlayerController();
		void Initialize();
		void Update();
		void Render();
		sf::Vector2f GetPlayerPosition();
		Entity::EntityType GetEntityOwnerType();
	};
}
