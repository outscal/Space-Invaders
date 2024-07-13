#pragma once
#include <SFML/Graphics.hpp>
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Entity\EntityConfig.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collision/ICollider.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups/PowerupConfig.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player/PlayerModel.h"
namespace Player
{
	class PlayerView;

	enum class PlayerState;

	class PlayerController : public Collision::ICollider
	{
	private:
		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		PlayerView* player_view;
		PlayerModel* player_model;
		
		void ProcessPlayerInput();
		void MoveRight();
		void MoveLeft();

		bool ProcessBulletCollision(ICollider* other_collider);
		bool ProcessPowerupCollision(ICollider* other_collider);
		bool ProcessEnemyCollision(ICollider* other_collider);
		void UpdateFreezeDuration();
		void FreezePlayer();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool b_tripple_laser = false);
		void FireBullet(sf::Vector2f position);

		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

	public:
		PlayerController(Entity::EntityType owner_type);
		~PlayerController();
		
		void Initialize();
		void Update();
		void Render();
		
		void Reset();
		
		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		sf::Vector2f GetPlayerPosition();
		PlayerState GetPlayerState();
		Entity::EntityType GetEntityOwnerType();
		
		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* other_collider) override;
	};
}
