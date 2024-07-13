#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::Initialize() 
	{
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage();
	}
	void GameplayView::CreateUIElements()
	{
		background_image = new ImageView();
	}
	void GameplayView::InitializeImage()
	{
		background_image->Initialize(GetBackgroundTexturePath(), game_window->getSize().x, game_window->getSize().y, background_position);
	}
	sf::String GameplayView::GetBackgroundTexturePath()
	{
		return Config::background_texture_path;
	}
	void GameplayView::Update() 
	{
		background_image->SetPosition(background_position);
		background_image->Update();
	}
	void GameplayView::Render() 
	{ 
		//game_window->draw(background_sprite); 
		background_image->Render();
	}
	void GameplayView::Destroy()
	{
		delete(background_image);
	}
}