#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\EventService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"

EventService::EventService() 
{ 
	game_window = nullptr;
	game_event.type = sf::Event::GainedFocus;
}
EventService::~EventService() = default;

void EventService::Initialize()
{
	game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
}
void EventService::Update()
{

}
void EventService::ProcessEvents()
{
	if (IsGameWindowOpen())
	{
		while (game_window->pollEvent(game_event))
		{
			//Check for window closure
			if (GameWindowWasClosed() || HasQuitGame())
			{
				game_window->close();
			}
		}
			
	}
}
bool EventService::HasQuitGame() { return (IsKeyboardEvent() && PressedEscapeKey()); }

bool EventService::IsKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }

bool EventService::PressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }

bool EventService::IsGameWindowOpen()  { return game_window != nullptr; }

bool EventService::GameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

bool EventService::PressedLeftKey(){ return game_event.key.code == sf::Keyboard::Left; }
bool EventService::PressedRightKey() { return game_event.key.code == sf::Keyboard::Right; }