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

		const sf::Vector2f initialPlayerPosition = sf::Vector2f(500.0f, 500.0f);
		sf::Vector2f playerPosition;
		PlayerState playerState; //Declaration
		int playerScore;

	public:

		const sf::Vector2f leftScreenSide = sf::Vector2f(50.0f, 0.0f);
		const sf::Vector2f rightScreenSide = sf::Vector2f(700.0f, 0.0f);

		const float playerMovementSpeed = 200.0f;
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
