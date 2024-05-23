#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\PlayerService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\ServiceLocator.h"


PlayerService::PlayerService()
{
	game_window = nullptr;
}
	//PlayerService(int hp, int moveSpeed);
PlayerService::~PlayerService() = default;
//Life Cycle methods
void PlayerService::Initialize()
{
	game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	InitializePlayerSprite();
}
void PlayerService::Update()
{
	ProcessPlayerInput();
	ship_Sprite.setPosition(GetPosition());
}
void PlayerService::Render()
{
	game_window->draw(ship_Sprite);
}
void PlayerService::ProcessPlayerInput()
{	
	//Get the event service object created in service locator
	EventService* event_service = ServiceLocator::GetInstance()->GetEventService(); 
	
	// Handle keyboard input
	if (event_service->IsKeyboardEvent()) 
	{
		if (event_service->PressedLeftKey())
		{
			move(-1.0f * GetMovementSpeed());
		}
		if (event_service->PressedRightKey())
		{
			move(1.0f * GetMovementSpeed());
		}
	}
}
void PlayerService::InitializePlayerSprite()
{
	if (ship_Texture.loadFromFile(ship_Texture_path))
	{
		ship_Sprite.setTexture(ship_Texture);
	}
}
//void PlayerService::TakeDamage() {}
void PlayerService::Move(float offsetX) 
{
	position.x += offsetX;
}
//void PlayerService::ShootBullets() {}

sf::Vector2f PlayerService::GetPosition() { return position; }
int PlayerService::GetMovementSpeed() { return movementSpeed; }
