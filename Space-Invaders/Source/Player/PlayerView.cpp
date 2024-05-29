#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
namespace Player
{
	using namespace Global;
	PlayerView::PlayerView() {}
	PlayerView::~PlayerView() {}

	void PlayerView::Initialize(PlayerController* controller)
	{
		player_controller = controller;
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializePlayerSprite();
	}
	void PlayerView::InitializePlayerSprite()
	{
		if (player_texture.loadFromFile(player_texture_path))
		{
			player_sprite.setTexture(player_texture);
			ScalePlayerSprite();
		}
	}
	void PlayerView::ScalePlayerSprite()
	{
		player_sprite.setScale(
			static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
			static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y);
	}
	void PlayerView::Update()
	{
		player_sprite.setPosition(player_controller->GetPlayerPosition());
	}
	void PlayerView::Render()
	{
		game_window->draw(player_sprite);
	}

}
