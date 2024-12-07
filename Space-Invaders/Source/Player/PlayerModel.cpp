#include <iostream>
using namespace std;
#include "../../HeaderFiles/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel() {

	}
	PlayerModel::~PlayerModel() {

	}
	void PlayerModel::initialize()
	{
		Reset();
	}
	void PlayerModel::Reset() {
		playerState = PlayerState::ALIVE; //set state to alive
		playerPosition = initialPlayerPosition;
		playerScore = 0;

	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return playerPosition;

	}
	void PlayerModel::setPlayerPosition(sf::Vector2f position) {
		playerPosition = position;
	}

	int PlayerModel::getPlayerScore() {
		return playerScore;
	}

	void PlayerModel::setPlayerScore(int score) {
		playerScore = score;
	}
	PlayerState PlayerModel::getPlayerState() {
		return playerState;
	}
	void PlayerModel::setPlayerState(PlayerState state)
	{
		playerState = state;

	}
}