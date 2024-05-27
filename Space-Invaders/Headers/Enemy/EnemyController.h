#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{	
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:
		EnemyView* enemy_view;
		EnemyModel* enemy_model;
		//manage movement methods
		void Move();
		void MoveLeft();
		void MoveRight();
		void MoveDown();
	public:
		EnemyController();
		~EnemyController();
	
		//Lifecycle Methods
		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
	};
}