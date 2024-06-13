#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerController.h"


namespace Element
{
	namespace Bunker
	{
		BunkerController::BunkerController() { bunker_view = new BunkerView(); }

		BunkerController::~BunkerController() { delete(bunker_view); }

		void BunkerController::Initialize(BunkerData data)
		{
			bunker_data = data;
			bunker_view->Initialize(this);
		}

		void BunkerController::Update() { bunker_view->Update(); }

		void BunkerController::Render() { bunker_view->Render(); }

		sf::Vector2f BunkerController::GetBunkerPosition() { return bunker_data.position; }
	}
}