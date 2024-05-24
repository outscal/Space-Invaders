#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\PlayerService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerController.h"

PlayerService::PlayerService()
{
	player_controller = new PlayerController();
}
PlayerService::~PlayerService()
{
	delete(player_controller);
}
//Life Cycle methods
void PlayerService::Initialize()
{
	player_controller->Initialize();
}
void PlayerService::Update()
{
	player_controller->Update();
}
void PlayerService::Render()
{	
	player_controller->Render();
}