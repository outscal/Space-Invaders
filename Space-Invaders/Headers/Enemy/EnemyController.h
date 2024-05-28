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
		virtual void Move();
		void MoveLeft();
		void MoveRight();
		void MoveDown();
	public:
		EnemyController();
		virtual ~EnemyController();
	
		//Lifecycle Methods
		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
	};
}