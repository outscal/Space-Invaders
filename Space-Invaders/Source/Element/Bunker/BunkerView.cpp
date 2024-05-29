#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
namespace Element
{
	namespace Bunker
	{
		using namespace Global;

		BunkerView::BunkerView() { }

		BunkerView::~BunkerView() { }
		void BunkerView::Initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeImage();
		}
		void BunkerView::InitializeImage()
		{
			if (bunker_texture.loadFromFile(bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				ScaleSprite();
			}
		}
		void BunkerView::ScaleSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_sprite_width) / bunker_sprite.getTexture()->getSize().x,
				static_cast<float>(bunker_sprite_height) / bunker_sprite.getTexture()->getSize().y
			);
		}
		void BunkerView::Update()
		{
			bunker_sprite.setPosition(bunker_controller->GetBunkerPosition());
		}

		void BunkerView::Render()
		{
			game_window->draw(bunker_sprite);
		}
	}
}

