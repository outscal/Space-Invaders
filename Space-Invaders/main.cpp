#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GameService.h"
#include <iostream>

int main()
{
	GameService* game_service = new GameService();
	game_service->Ignite();
	while (game_service->isRunning())
	{
		game_service->Update();
		game_service->Render();
	}
}