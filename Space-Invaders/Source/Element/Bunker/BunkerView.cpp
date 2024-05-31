#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace UI::UIElement;

		BunkerView::BunkerView() { CreateUIElements(); }

		BunkerView::~BunkerView() { Destroy(); }
		void BunkerView::Initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			//game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeImage();
		}
		void BunkerView::CreateUIElements()
		{
			bunker_image = new ImageView();
		}
		void BunkerView::InitializeImage()
		{
			bunker_image->Initialize(GetBunkerTexturePath(), bunker_sprite_width, bunker_sprite_height, bunker_controller->GetBunkerPosition());
		}
		void BunkerView::Update()
		{
			bunker_image->SetPosition(bunker_controller->GetBunkerPosition());
			bunker_image->Update();
		}
		void BunkerView::Render()
		{
			//game_window->draw(bunker_sprite);
			bunker_image->Render();
		}
		sf::String BunkerView::GetBunkerTexturePath()
		{
			return Config::bunker_texture_path;
		}
		void BunkerView::Destroy()
		{
			delete(bunker_image);
		}
	}
}

