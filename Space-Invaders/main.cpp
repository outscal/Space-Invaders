#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include <iostream>
using namespace Main;
int main()
{
	GameService* game_service = new GameService();
	game_service->Ignite();
	
	while (game_service->isRunning())
	{	
		game_service->Render();
		game_service->Update();
		
	}
}