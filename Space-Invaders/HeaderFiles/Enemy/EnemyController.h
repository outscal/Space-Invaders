#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy {

	class EnemyModel;
	class EnemyView;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController 
	{
	protected:

		EnemyView* enemyView;
		EnemyModel* enemyModel;

		virtual void move() = 0;
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();
		//void moveRight();
		//void moveLeft();
		//void moveDown();

	public:
		
		EnemyController(EnemyType setType);
	    virtual ~EnemyController();

		//Lifecycle

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		EnemyType getEnemyType();
		EnemyState getEnemyState();
		

	
	};

}
