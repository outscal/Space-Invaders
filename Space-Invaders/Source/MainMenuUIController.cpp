#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\MainMenu\MainMenuUIController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		MainMenuUIController::MainMenuUIController() { game_window = nullptr; }
		
		void MainMenuUIController::Initialize()
		{
			game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		}
		void MainMenuUIController::Update()
		{

		}
		void MainMenuUIController::Render()
		{

		}
	}
}