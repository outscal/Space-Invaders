#pragma once
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Player/PlayerController.h"
//TO maintain and store data of the player

namespace Player 
{
	enum class PlayerState {

		ALIVE,
		DEAD

	};

	class PlayerModel {

	private:

		const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f playerPosition;
		PlayerState playerState; //Declaration
		int playerScore;

	public:

		const sf::Vector2f leftScreenSide = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f rightScreenSide = sf::Vector2f(1800.0f, 950.0f);

		const float playerMovementSpeed = 350.0f;
		PlayerModel();
		~PlayerModel();

		void Reset();
		void initialize();


		//getters and setters
		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);


		int getPlayerScore();
		void setPlayerScore(int score);

		//new getter and setter
		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);


	};
}
