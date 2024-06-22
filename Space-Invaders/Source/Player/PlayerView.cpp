#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"


namespace Player
{
	using namespace Global;
	PlayerView::PlayerView()
	{
	}

	PlayerView::~PlayerView() {};

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::update()
	{
		player_sprite.setPosition(player_controller->getPosition());
	}

	void PlayerView::render()
	{
		game_window->draw(player_sprite);
	}

	void PlayerView::initializePlayerSprite()
	{
		if (player_texture.loadFromFile(Config::player_texture_path))
		{
			player_sprite.setTexture(player_texture);
			scaleSprite();
		}
	}

	void PlayerView::scaleSprite()
	{
		player_sprite.setScale(
			static_cast<float>(sprite_width) / player_sprite.getTexture()->getSize().x,
			static_cast<float>(sprite_height) / player_sprite.getTexture()->getSize().y
		);
	}

}
