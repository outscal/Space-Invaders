#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayService.h"
namespace Gameplay
{
	GameplayService::GameplayService() { gameplay_controller = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplay_controller); }

	void GameplayService::Initialize() { gameplay_controller->Initialize(); }

	void GameplayService::Update() { gameplay_controller->Update(); }

	void GameplayService::Render() { gameplay_controller->Render(); }
}


