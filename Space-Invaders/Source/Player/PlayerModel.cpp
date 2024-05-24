#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerModel.h"

PlayerModel::PlayerModel()
{

}
PlayerModel::~PlayerModel()
{

}
void PlayerModel::Initialize(){ Reset(); }

void PlayerModel::Reset()
{
	player_state = PlayerState::ALIVE;
	player_position = initial_player_position;
	player_score = 0;
}

sf::Vector2f PlayerModel::GetPlayerPosition()
{
	return player_position;
}

void PlayerModel::SetPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}
int PlayerModel::GetPlayerScore() { return player_score; }
void PlayerModel::SetPlayerScore(int score) { player_score = score; }
PlayerState PlayerModel::GetPlayerState() { return player_state; }
void PlayerModel::SetPLayerState(PlayerState state) { player_state = state; }
//bool PlayerModel::GetPlayerAlive()
//{
//	return player_alive;
//}
//void PlayerModel::SetPlayerAlive(bool alive)
//{
//	player_alive = alive;
//}