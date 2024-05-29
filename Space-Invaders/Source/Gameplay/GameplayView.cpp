#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::Initialize() 
	{
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeBackgroundSprite();
	}

	void GameplayView::InitializeBackgroundSprite() 
	{
		if (background_texture.loadFromFile(background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			ScaleBackgroundSprite();
		}
	}
	void GameplayView::ScaleBackgroundSprite() 
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}
	void GameplayView::Update() { }

	void GameplayView::Render() { game_window->draw(background_sprite); }
}