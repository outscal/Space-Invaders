#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;
	class EnemyController
	{
	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

		virtual void move();
		void moveLeft();
		void moveRight();
		void moveDown();

		float getVerticalMoveSpeed();
		void setVerticalMoveSpeed(float move_speed);
		float getHorizontalMoveSpeed();
		void setHorizontalMoveSpeed(float move_speed);

		void getRandomInitialPosition();
		void handleOutOfBounds();


	private:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;
		float vertical_movement_speed;
		float horizontal_movement_speed;

	};
}


