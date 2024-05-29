#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{	
	class EnemyView;
	class EnemyModel;
	enum class EnemyType;
	enum class EnemyState;

	class EnemyController
	{
	private:
		
		//manage movement methods
		
		//void MoveLeft();
		//void MoveRight();
		//void MoveDown();
	protected:
		EnemyView* enemy_view;
		EnemyModel* enemy_model;
		sf::Vector2f GetRandomInitialPosition();
		void HandleOutOfBounds();
		virtual void Move() = 0;//pure virtual
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();
		//Lifecycle Methods
		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyState GetEnemyState();
		EnemyType GetEnemyType();
	};
}