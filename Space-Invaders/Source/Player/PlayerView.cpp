#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;
	PlayerView::PlayerView() { CreateUIElements(); }
	PlayerView::~PlayerView() { Destroy(); }

	void PlayerView::Initialize(PlayerController* controller)
	{
		player_controller = controller;
		//game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage();
	}
	void PlayerView::CreateUIElements()
	{
		player_image = new ImageView();
	}
	void PlayerView::InitializeImage()
	{
		player_image->Initialize(GetPlayerTexturePath(), player_sprite_width, player_sprite_height, player_controller->GetPlayerPosition());
	}
	sf::String PlayerView::GetPlayerTexturePath()
	{
		return Config::player_texture_path;
	}
	void PlayerView::Update()
	{
		player_image->SetPosition(player_controller->GetPlayerPosition());
	}
	void PlayerView::Render()
	{
		//game_window->draw(player_sprite);
		player_image->Render();
	}
	void PlayerView::Destroy() { delete player_image; }
}
