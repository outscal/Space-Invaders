#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayController.h"

namespace Gameplay
{
	GameplayController::GameplayController() { gameplay_view = new GameplayView(); }

	GameplayController::~GameplayController() { delete (gameplay_view); }

	void GameplayController::Initialize() { gameplay_view->Initialize(); }

	void GameplayController::Update() { gameplay_view->Update(); }

	void GameplayController::Render() { gameplay_view->Render(); }
}