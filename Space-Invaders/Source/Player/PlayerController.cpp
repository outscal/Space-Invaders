#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerModel.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerView.h"
#include<algorithm>
PlayerController::PlayerController()
{
	player_model = new PlayerModel();
	player_view = new PlayerView();
}
PlayerController::~PlayerController() 
{
	delete (player_view);
	delete (player_model);
}
void PlayerController::Initialize()
{	
	player_model->Initialize();
	player_view->Initialize(this);//error noted 
}
void PlayerController::Update()
{
	ProcessPlayerInput();
	player_view->Update();
}
void PlayerController::Render()
{
	player_view->Render();
}
sf::Vector2f PlayerController::GetPlayerPosition()
{
	return player_model->GetPlayerPosition();
}
void PlayerController::ProcessPlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MoveRight();
	}
}
void PlayerController::MoveLeft()
{
	sf::Vector2f currentPosition = player_model->GetPlayerPosition();
	currentPosition.x -= player_model->player_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
	player_model->SetPlayerPosition(currentPosition);
}
void PlayerController::MoveRight()
{
	sf::Vector2f currentPosition = player_model->GetPlayerPosition();
	currentPosition.x += player_model->player_movement_speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
	player_model->SetPlayerPosition(currentPosition);
}