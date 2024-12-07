#include <iostream>
using namespace std;
#include "../../HeaderFiles/Player/PlayerView.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Player/PlayerController.h"

namespace Player {

	using namespace Global;

	void PlayerView::initialize() {
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::initializePlayerSprite()
	{
		if (playerTexture.loadFromFile(player_texture_path))
		{
			playerSprite.setTexture(playerTexture);
		}
		scalePlayerSprite();
	}

	void PlayerView::scalePlayerSprite() {
		//Here we find the factor to scale our sprites with. Ignore the static_cast for now, we will discuss it later.

		playerSprite.setScale(
			static_cast<float>(spriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(spriteHeight) / playerSprite.getTexture()->getSize().y);
	}

	PlayerView::PlayerView() {

	}
	PlayerView::~PlayerView() {

	}

	void PlayerView::initialize(PlayerController* controller) {

		playerController = controller;
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::update() {
		playerSprite.setPosition(playerController->getPlayerPosition());

	}

	void PlayerView::render() {
		gameWindow->draw(playerSprite);
	}
}

