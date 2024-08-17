#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerView.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Global\ServiceLocator.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerController.h"
PlayerView::PlayerView()
{
}

PlayerView::~PlayerView()
{
}

void PlayerView::Initialise(PlayerController* controller)
{
	player_controller = controller;
	game_window = ServiceLocator::GetInstance()->getGraphicService()->GetGameWindow();
	initializePlayerSprite();
}
void PlayerView::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
		scaleSprite();
	}
}

void PlayerView::scaleSprite()
{
	player_sprite.setScale(
		//Here we find the factor to scale our sprites with. Ignore the static_cast for now, we will discuss it later.
		static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
		static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y);
}






void PlayerView::Update()
{
	player_sprite.setPosition(player_controller->getPlayerPosition());
}

void PlayerView::Render()
{
	game_window->draw(player_sprite);
}
