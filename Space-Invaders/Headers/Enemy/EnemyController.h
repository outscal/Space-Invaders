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
	protected:
		float vertical_movement_speed = 30.f;
		float horizontal_movement_speed = 200.0f;

		float rate_of_fire = 3.f; //we want to fire the bullet every 3 seconds
		float elapsed_fire_duration = 0.f; //variable to check how long it has been since we last fired

		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		void UpdateFireTimer();
		void ProcessBulletFire();
		virtual void FireBullet() = 0;
		
		virtual void Move() = 0;//pure virtual func
		sf::Vector2f GetRandomInitialPosition();
		void HandleOutOfBounds();
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