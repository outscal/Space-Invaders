#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Entity\EntityConfig.h"

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		FROZEN,
		DEAD
		//Add more states when necessary
	};
	class PlayerModel
	{
	private:
		const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);

		sf::Vector2f player_position;
		Entity::EntityType owner_type;
		PlayerState player_state;
		int player_score;\

		bool b_shield;
		bool b_rapid_fire;
		bool b_tripple_laser;
	
	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);
		const sf::Vector2f second_weapon_position_offset = sf::Vector2f(45.f, 0.f);
		const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-45.f, 0.f);
		
		
		const float shiled_powerup_duration = 10.f;
		const float rapid_fire_powerup_duration = 10.f;
		const float tripple_laser_powerup_duration = 10.f;

		const float freeze_duration = 2.f;

		const float fire_cooldown_duration = 0.2f;
		const float rapid_fire_cooldown_duration = 0.05f;
		const float tripple_laser_position_offset = 30.f;

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		const float player_movement_speed = 350.f;

		PlayerModel(Entity::EntityType owner_type);
		~PlayerModel();

		//LifeCycle Methods
		void Initialize();
		void Reset();

		//Getters and setters
		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);
		
		int GetPlayerScore();
		void SetPlayerScore(int score);

		PlayerState GetPlayerState();
		void SetPLayerState(PlayerState state);
		
		Entity::EntityType GetEntityOwnerType();

		bool IsShieldEnabled();
		bool IsRapidFireEnabled();
		bool isTrippleLaserEnabled();

		void SetShieldState(bool value);
		void SetRapidFireState(bool value);
		void SetTrippleFireState(bool value);
	};
}
