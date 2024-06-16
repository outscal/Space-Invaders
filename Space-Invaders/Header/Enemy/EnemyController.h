#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;
	enum class EnemyType;
	enum class EnemyState;
	class EnemyController
	{
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		

		 virtual void move() = 0;
	/*	void moveLeft();
		void moveRight();
		void moveDown();*/

	/*	float getVerticalMoveSpeed();
		void setVerticalMoveSpeed(float move_speed);
		float getHorizontalMoveSpeed();
		void setHorizontalMoveSpeed(float move_speed);*/

		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		EnemyType getEnemyType();
		EnemyState getEnemyState();
		sf::Vector2f getEnemyPosition();


	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;
	/*	float vertical_movement_speed;
		float horizontal_movement_speed;*/
	};
}


