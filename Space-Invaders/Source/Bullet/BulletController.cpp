#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletModel.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletConfig.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
namespace Bullet
{	
	using namespace Global;

	BulletController::BulletController(BulletType type, Entity::EntityType owner_type)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(type, owner_type);
	}
	BulletController::~BulletController()
	{
		delete (bullet_view);
		delete (bullet_model);
	}
	void BulletController::Initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_view->Initialize(this);
		bullet_model->Initialize(position, direction);
	}
	void BulletController::Update()
	{
		UpdateProjectilePosition();
		bullet_view->Update();
		HandleOutOfBounds();
	}
	void BulletController::Render()
	{
		bullet_view->Render();
	}
	void BulletController::UpdateProjectilePosition()
	{
		switch (bullet_model->GetMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			MoveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			MoveDown();
			break;
		}
	}
	void BulletController::MoveUp()
	{
		sf::Vector2f currentPosition = bullet_model->GetBulletPosition();
		currentPosition.y -= bullet_model->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		bullet_model->SetBulletPosition(currentPosition);
	}
	void BulletController::MoveDown()
	{
		sf::Vector2f currentPosition = bullet_model->GetBulletPosition();
		currentPosition.y += bullet_model->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		bullet_model->SetBulletPosition(currentPosition);
	}
	void BulletController::HandleOutOfBounds()
	{
		sf::Vector2f bulletPosition = GetProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
		}
	}
	

	sf::Vector2f BulletController::GetProjectilePosition() 
	{
		return bullet_model->GetBulletPosition();
	}
	BulletType BulletController::GetBulletType()
	{
		return bullet_model->GetBulletType();
	}
	Entity::EntityType BulletController::GetEntityOwner()
	{
		return bullet_model->GetEntityOwner();
	}
}