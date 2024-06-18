#include "../../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel() { }

PlayerModel::~PlayerModel() { }

void PlayerModel::initialize() { reset(); }

void PlayerModel::reset()
{
	player_state = PlayerState::ALIVE;
	player_position = initial_player_position;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return player_position;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}

PlayerState PlayerModel::getPlayerState()
{
	return player_state;
}

void PlayerModel::setPlayerState(PlayerState state)
{
	player_state = state;
}