#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{	
	class EnemyView;
	class EnemyModel;
	enum class EnemyType;

	class EnemyController
	{
	private:
		
		//manage movement methods
		virtual void Move()=0;//pure virtual
		void MoveLeft();
		void MoveRight();
		void MoveDown();
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();
		EnemyView* enemy_view;
		EnemyModel* enemy_model;
		EnemyType* enemy_type;
		//Lifecycle Methods
		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyType GetEnemyType();
	};
}