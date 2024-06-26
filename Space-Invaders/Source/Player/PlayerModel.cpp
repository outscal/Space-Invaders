#include "../../Header/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel()
	{
	}

	PlayerModel::~PlayerModel()
	{
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return current_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		current_position = position;
	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		current_position = initial_position;
		player_score = 0;
	}

	PlayerState PlayerModel::getPlayerAlive()
	{
		return player_state;;
	}

	void PlayerModel::setPlayerAlive(PlayerState state)
	{
		state = player_state;
	}
}

