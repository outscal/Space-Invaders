#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/BulletConfig.h"
//#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/Controllers/FrostBulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/Controllers/LaserBulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet/Controllers/TorpedoController.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;

	BulletService::BulletService() { }

	BulletService::~BulletService() { Destroy(); }

	void BulletService::Initialize() { }

	void BulletService::Update()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->Update();
	}

	void BulletService::Render()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->Render();
	}

	BulletController* BulletService::CreateBullet(BulletType bullet_type, Entity::EntityType owner_type)
	{
		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, owner_type);

		/*case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET);*/

		case::Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, owner_type);
		}
	}

	void BulletService::Destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++) delete (bullet_list[i]);
	}

	BulletController* BulletService::SpawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType owner_type)
	{
		BulletController* bullet_controller = CreateBullet(bullet_type,owner_type);

		bullet_controller->Initialize(position, direction);
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::DestroyBullet(BulletController* bullet_controller)
	{	
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		delete(bullet_controller);
		//printf("Bullet Destroyed");
	}
}