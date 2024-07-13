#pragma once
namespace Player
{
	class PlayerController;
	
	class PlayerService
	{

	private:
		PlayerController* player_controller;

	public:
		PlayerService(Entity::EntityType owner_type);
		virtual ~PlayerService();
		
		void Initialize();
		void Update();
		void Render();

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();
	
		void Reset();
	};
}
